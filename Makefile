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

INPUT_FILE = input_file
CMD1 = "cat"
CMD2 = "grep -i pipex"

OUTPUT_FILE = output_file

MAKE_EXTERNAL = make -C
SAFE_MKDIR = mkdir -p

COPY = cp -p

REMOVE = rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives
BINS_PATH = ./bin

HEADER_FILE = push_swap.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES =	main.c\
								init.c\
								exit.c\
								check.c\
								parse.c\
								free.c\
								helpers.c\
								algorithms.c\
								operations.c\
								math.c\
								sort_simple.c\
								sort_complex.c\
								execute.c\
								handlers.c\

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

VALID_TEST_ARGS = "1 -2 -123 5 32544"

all: $(NAME)

$(NAME): build_get_next_line build_libft $(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) -w -g $(OBJECTS) -o $(NAME) -L $(ARCHIVES_PATH) -I $(INCLUDES_PATH) $(EXTERNAL_LIBS) $(INTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	@$(SAFE_MKDIR) $(OBJECTS_PATH)
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
	./$(NAME) $(VALID_TEST_ARGS)

debug: $(NAME)
	gdb ./$(NAME) $(VALID_TEST_ARGS)

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) $(VALID_TEST_ARGS)

re:	fclean all

archives_clean:
	$(REMOVE) $(ARCHIVES_PATH)

clean:
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean archives_clean libft_clean get_next_line_clean
	$(REMOVE) $(NAME)

.PHONY: all run valgrind re fclean clean archives_clean libft_clean get_next_line_clean
