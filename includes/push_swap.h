/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/24 01:10:06 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP

/* libraries */
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
// # include <stddef.h>

/* internal libraries */
#include <libft.h>
#include <get_next_line.h>

/** literals */
#define STACK_MAX_SIZE 1024
#define STACK_SIMPLE_SORT_MAX_MEMBERS 5

//* constants */
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

typedef struct s_stack
{
	int top;
	int *vec;
}	t_stack;

typedef struct stack_pair
{
	t_stack *a;
	t_stack *b;
}	t_stack_pair;

/* handlers.c */
/**
 * @brief Handles the program exiting
 *
 * @param s The error message to be printed
 */
void		die(t_stack *self, const char *s, int errno);

int			init_stack(t_stack *self);

int			handle_parse_args(t_stack *self, int argc, char *argv[]);

bool		check_duplicate_number(t_stack *self, int *num);
bool		check_int(char *elem);

void		free_vec(void **vec);

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

int			parse_single_arg(t_stack *self, char *arg);

int			normalize(int *origin, size_t size);

int			min(t_stack *stack);
int			max(t_stack *stack);

int			handle_sort_stack(t_stack *stack);

void		push(t_stack *origin, t_stack *dest);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

void		handle_sort(t_stack *stack); //from third party
bool		ft_streq(const char *s1, const char *s2);

int			execute(char *op, t_stack *a, t_stack *b);
void		execute_recursively(char *op, t_stack *a, t_stack *b, int times);
void		execute_rotate_a(t_stack *a, int n);

int			simple_sort(t_stack *a);
int			simple_sort_complete(t_stack *a, t_stack *b);

void		complex_sort(t_stack *a, t_stack *b);

#endif
