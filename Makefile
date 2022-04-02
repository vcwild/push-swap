NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra

INTERNAL_LIBS = -lft -lgnl
EXTERNAL_LIBS = -lm

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)

GNL = libgnl.a
GNL_PATH = $(LIBS_PATH)/get_next_line
GNL_ARCHIVE = $(ARCHIVES_PATH)/$(GNL)

MAKE_EXTERNAL = make -C
SAFE_MKDIR = mkdir -p

COPY = cp -p

REMOVE = rm -rf

# /* Push Swap */

OBJECTS_PATH = ./objects/push_swap
SOURCES_PATH = ./sources/push_swap
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives
BINS_PATH = ./bin

HEADER_FILE = push_swap.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES =	main.c\
								exit.c\
								check.c\
								parse.c\
								helpers.c\
								algorithms.c\
								operations.c\
								math.c\
								sort_simple.c\
								sort_complex.c\
								execute.c\
								handlers.c\
								find.c\
								move.c\

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

# /* Checkerlib */

CHECKER_NAME = checker
CHECKER_HEADER_FILE = checker.h
CHECKER_HEADER = $(addprefix $(INCLUDES_PATH)/,$(CHECKER_HEADER_FILE))
CHECKER_SOURCES_PATH = ./sources/checker

CHECKER_SOURCE_FILES = exec.c\
											 utils.c\
											 checker.c\

CHECKER_OBJECTS_PATH = ./objects/checker
CHECKER_OBJECTS = $(addprefix $(CHECKER_OBJECTS_PATH)/,$(subst .c,.o,$(CHECKER_SOURCE_FILES)))

SOURCES_FOR_CHECKER = parse.c\
											helpers.c\
											operations.c\
											check.c\
											exit.c\

OBJECTS_FOR_CHECKER = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCES_FOR_CHECKER)))

VALID_TEST_ARGS = "1 -2 -123 5 32544"
TEST_CLI_CMD =  python3 -m unittest tests.test_cli -c

all: $(NAME)

$(NAME): build_get_next_line build_libft $(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) -w -g $(OBJECTS) -o $(NAME) -L $(ARCHIVES_PATH) -I $(INCLUDES_PATH) $(EXTERNAL_LIBS) $(INTERNAL_LIBS)

$(CHECKER_NAME): $(CHECKER_OBJECTS) $(CHECKER_HEADER) $(NAME)
	@$(CC) $(CFLAGS) -w -g $(CHECKER_OBJECTS) $(OBJECTS_FOR_CHECKER) -o $(CHECKER_NAME) -L $(ARCHIVES_PATH) -I $(INCLUDES_PATH) $(EXTERNAL_LIBS) $(INTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $< $(EXTERNAL_LIBS)

$(CHECKER_OBJECTS_PATH)/%.o: $(CHECKER_SOURCES_PATH)/%.c $(CHECKER_HEADER) $(HEADER)
	@$(SAFE_MKDIR) $(CHECKER_OBJECTS_PATH)
	@$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $< $(EXTERNAL_LIBS)

local_mkdir:
	@$(SAFE_MKDIR) $(BINS_PATH)

build_libft:
	@$(MAKE_EXTERNAL) $(LIBFT_PATH)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(LIBFT_PATH)/$(LIBFT) $(ARCHIVES_PATH)

build_get_next_line:
	@$(MAKE_EXTERNAL) $(GNL_PATH)
	@$(SAFE_MKDIR) $(ARCHIVES_PATH)
	@$(COPY) $(GNL_PATH)/$(GNL) $(ARCHIVES_PATH)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean
	$(REMOVE) $(LIBFT_ARCHIVE)

get_next_line_clean:
	$(MAKE_EXTERNAL) $(GNL_PATH) fclean
	$(REMOVE) $(GNL_ARCHIVE)

run: $(NAME)
	@./$(NAME) $(VALID_TEST_ARGS)

debug: $(NAME)
	gdb ./$(NAME) $(VALID_TEST_ARGS)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(VALID_TEST_ARGS)

test: $(NAME)
	@$(TEST_CLI_CMD) > /dev/null

bonus: $(CHECKER_NAME)

re:	fclean all

archives_clean:
	$(REMOVE) $(ARCHIVES_PATH)

clean:
	$(REMOVE) $(OBJECTS_PATH) $(CHECKER_OBJECTS_PATH)

fclean: clean archives_clean libft_clean get_next_line_clean
	$(REMOVE) $(NAME) $(CHECKER_NAME)

.PHONY: all run valgrind re fclean clean archives_clean libft_clean get_next_line_clean test
