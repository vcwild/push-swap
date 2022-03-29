/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:29:44 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:14:39 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute(char *op, t_stack *a, t_stack *b)
{
	if (not_strncmp(op, PA))
		push(b, a);
	else if (not_strncmp(op, PB))
		push(a, b);
	else if (not_strncmp(op, SA))
		swap(a);
	else if (not_strncmp(op, SB))
		swap(b);
	else if (not_strncmp(op, RA))
		rotate(a);
	else if (not_strncmp(op, RB))
		rotate(b);
	else if (not_strncmp(op, RRA))
		reverse_rotate(a);
	else if (not_strncmp(op, RRB))
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
	return (0);
}

void	execute_recursively(char *op, t_stack *a, t_stack *b, int times)
{
	if (times <= 0)
		return ;
	execute(op, a, b);
	execute_recursively(op, a, b, times - 1);
}

void	execute_rotate_closest_above_and_push(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->vec[b->top];
	to_move = find_closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	execute_rotate(a, to_move, RA, RRA);
	execute(PA, a, b);
}

void	execute_rotate(t_stack *self, int n, char *op, char *reverse_op)
{
	int	find;

	find = self->top;
	while (find >= 0 && self->vec[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < self->top / 2)
	{
		if (not_strncmp(op, RA))
			execute_recursively(reverse_op, self, NULL, find + 1);
		else
			execute_recursively(reverse_op, NULL, self, find + 1);
	}
	else
	{
		if (not_strncmp(op, RA))
			execute_recursively(op, self, NULL, self->top - find);
		else
			execute_recursively(op, NULL, self, self->top - find);
	}
}
