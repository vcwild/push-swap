/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:17:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP

/* libraries */
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdio.h>

/* internal libraries */
# include <libft.h>
# include <get_next_line.h>

/* literals */
# define STACK_MAX_SIZE 1024
# define STACK_SIMPLE_SORT_MAX_MEMBERS 5

/* constants */
# define SA "sa"
# define SS "ss"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

/**
 * @brief The stack structure definition
 * @top: the top of the stack
 * @vec: the stack vector of integers
 */
typedef struct s_stack
{
	int	top;
	int	*vec;
}	t_stack;

/**
 * @brief Handles the program exiting
 *
 * @param self The stack instance to be cleaned
 * @param msg The error message to be printed
 */
void		die(t_stack *self, const char *s, int errno);

/**
 * @brief A handler to deal with the input arguments
 *
 * @param self The instance of the stack to push the numbers to
 * @param argc The number of arguments given
 * @param argv The arguments given
 * @return int Returns 0 on success, and 1 on error.
 */
int			handle_parse_args(t_stack *self, int argc, char *argv[]);

/**
 * @brief Checks the stack for duplicate numbers
 *
 * @param self The stack instance to be checked
 * @param num The reference to the number to be checked
 * @return true
 * @return false
 */
bool		check_duplicate_number(t_stack *self, int *num);

/**
 * @brief Verifies if a number is not an integer
 *
 * @param elem The reference to the number to be checked
 * @return true Returns true if the number is not an integer
 * @return false Returns false if the number is an integer
 */
bool		check_int(char *elem);

/**
 * @brief Checks if the stack is sorted
 *
 * @param self The stack to be checked
 * @return true When the stack is sorted
 * @return false When the stack is not sorted
 */
bool		is_sorted(t_stack *self);

/**
 * @brief Reverses the given vector.
 * This is needed so that the vector is the inverse of the given input.
 *
 * @param vec The vector to be reversed
 * @param size The size of the vector
 */
void		reverse_vec(int *vec, size_t size);

/**
 * @brief Wrapper to the inverse of the strncmp function.
 *
 * @param s1 The first string to be compared
 * @param s2 The second string to be compared
 *
 * @return false When the strings are equal
 */
bool		not_strncmp(const char *s1, const char *s2);

/**
 * @brief Normalizes the input.
 *
 * @param origin A reference to the vector to be normalized
 * @param size The size of the vector
 * @return int Returns 0 on success, and 1 on error.
 */
int			normalize(int *origin, size_t size);

/**
 * @brief Wrapper to find the minimum value in the stack instance vector.
 *
 * @param self The stack instance to be checked
 * @return int Returns the minimum value in the stack instance vector.
 */
int			min(t_stack *self);

/**
 * @brief Wrapper to find the maximum value in the stack instance vector.
 *
 * @param self The stack instance to be checked
 * @return int Returns the maximum value in the stack instance vector.
 */
int			max(t_stack *self);

/**
 * @brief Pushes a number from the `origin` stack vector to the
 * `dest` stack vector.
 *
 * @param origin The origin stack
 * @param dest The destination stack
 */
void		push(t_stack *origin, t_stack *dest);

/**
 * @brief Swaps the first two elements of the stack instance vector.
 *
 * @param self The stack instance to be swapped
 */
void		swap(t_stack *self);

/**
 * @brief Rotates the stack instance vector to the left,
 * moving the first element to the end and moving every
 * other element one place to the left.
 *
 * @param self The stack instance to be rotated
 */
void		rotate(t_stack *self);

/**
 * @brief Reverse rotates the stack instance vector to the right,
 * moving the last element to the beginning and moving every other
 * element one place to the right.
 *
 * @param self The stack instance to be reverse rotated
 */
void		reverse_rotate(t_stack *self);

/**
 * @brief A handler function for the stack sorting
 *
 * @param self The stack instance to be sorted
 * @return int
 */
int			handle_sort(t_stack *self);

/**
 * @brief An ugly function to handle the execution of the commands
 *
 * @param op The operation received
 * @param a The first stack
 * @param b The second stack
 * @return int Returns 0 on success, does not return on failure
 */
int			execute(char *op, t_stack *a, t_stack *b);

/**
 * @brief Executes the given operation for both stacks recursively
 *
 * @param op The operation to be executed
 * @param a The first stack
 * @param b The second stack
 * @param times The number of times to be executed
 */
void		execute_recursively(char *op, t_stack *a, t_stack *b, int times);

/**
 * @brief Executes a rotation on the given stack instance
 *
 * @param self The stack to be rotated
 * @param n The number to move from the stack
 * @param op The rotation operation to be executed
 * @param reverse_op The reverse rotation operation to be executed
 */
void		execute_rotate(t_stack *self, int n, char *op, char *reverse_op);

/**
 * @brief Executes a rotation for the closest element to the top of the stack
 * and also pushes the top element from the stack `a` to the stack `b`.
 *
 * @param a The first stack
 * @param b The second stack
 */
void		execute_rotate_closest_above_and_push(t_stack *a, t_stack *b);

/**
 * @brief Searches from the top of the stack a valid number within range
 * of `min_i` and `max_i`
 *
 * @param a The instance of the stack to be searched
 * @param min_index The minimum index to be searched
 * @param max_index The maximum index to be searched
 * @return int Returns the number found, or -1 if no number was found
 */
int			find_from_top(t_stack *a, int min_index, int max_index);

/**
 * @brief Searches from the bottom of the stack a valid number within
 * range of `min_i` and `max_i`
 *
 * @param a The instance of the stack to be searched
 * @param min_index The minimum index to be searched
 * @param max_index The maximum index to be searched
 * @return int Returns the number found, or -1 if no number was found
 */
int			find_from_bottom(t_stack *a, int min_index, int max_index);

/**
 * @brief Moves the splitted chunk to the top of the stack
 *
 * @param a The first stack
 * @param b The second stack
 * @param min The minimum range to be searched
 * @param max The maximum range to be searched
 */
void		move_chunk_to_top(t_stack *a, t_stack *b, int min, int max);

/**
 * @brief Moves the closest element to the top of the stack to the top
 * of the stack
 *
 * @param b The second stack instance
 */
void		move_closest_index_from_b_to_top(t_stack *b);

/**
 * @brief Finds the closest element to the top of the stack
 *
 * @param a The first stack instance
 * @param n The number on the top of the stack
 * @return int Returns the number of the closest element to the top of the stack
 */
int			find_closest_above(t_stack *a, int n);

/**
 * @brief Deals with every possible case of for a simple sort routine
 *
 * @param a The first stack instance
 * @return int Returns 0 on success and nothing on failure
 */
int			simple_sort(t_stack *a);

/**
 * @brief Deals with every possible case of for a simple sort algorithm
 *
 * @param a The first stack instance
 * @param b The second stack instance
 * @return int Returns 0 on success and nothing on failure
 */
int			simple_sort_complete(t_stack *a, t_stack *b);

/**
 * @brief Deals with every possible case of for complex sort algorithm
 * up to 500 elements
 *
 * @param a The first stack instance
 * @param b The second stack instance
 */
void		complex_sort(t_stack *a, t_stack *b);

#endif
