/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:17 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/02 21:16:24 by vwildner         ###   ########.fr       */
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
void	die(t_stack *self, const char *s, int errno);

int		init_stack(t_stack *self);

int handle_parse_args(t_stack *self, int argc, char *argv[]);

bool	check_duplicate_number(t_stack *self, int *num);
bool	check_int(char *elem);

void	free_vec(void **vec);

#endif
