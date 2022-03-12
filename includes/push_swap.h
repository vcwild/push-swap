/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/12 14:31:43 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP

/* libraries */
# include <unistd.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdio.h>
// # include <stddef.h>

/* internal libraries */
# include <libft.h>
# include <get_next_line.h>

#define STACK_MAX_SIZE 1024

typedef struct s_stack
{
	int	top;
	int	*vec;
}		t_stack;

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

int			normalize(int *origin, size_t size);

#endif
