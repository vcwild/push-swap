/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:16:44 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 12:10:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Cleans all of the allocated memory
 *
 * @param self The stack instance to be cleaned
 */
static void	janitor(t_stack *self)
{
	if (self->vec)
		free(self->vec);
}

/**
 * @brief Applies a linebreak to the output if no linebreak
 * was previously detected
 *
 * @param msg The message to be scanned for a linebreak
 */
static void	handle_linebreak(const char *msg)
{
	int	pos;

	pos = strlen(msg) - 1;
	if (msg[pos] != '\n')
		write(STDERR_FILENO, "\n", 1);
}

static void	handle_error(const char *msg, int errno)
{
	if (errno)
	{
		write(STDERR_FILENO, "Error", 6);
		handle_linebreak(msg);
	}
}

void	die(t_stack *self, const char *msg, int errno)
{
	handle_error(msg, errno);
	janitor(self);
	exit(errno);
}
