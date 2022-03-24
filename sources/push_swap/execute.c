/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:29:44 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 22:03:16 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, PA))
		push(b, a);
	else if (ft_streq(op, PB))
		push(a, b);
	else if (ft_streq(op, SA))
		swap(a);
	else if (ft_streq(op, SB))
		swap(b);
	else if (ft_streq(op, RA))
		rotate(a);
	else if (ft_streq(op, RB))
		rotate(b);
	else if (ft_streq(op, RRA))
		reverse_rotate(a);
	else if (ft_streq(op, RRB))
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

void	execute_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->vec[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		execute_recursively(RRA, a, NULL, find + 1);
	else
		execute_recursively(RA, a, NULL, a->top - find);
}

void	execute_rotate_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (find >= 0 && b->vec[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		execute_recursively(RRB, NULL, b, find + 1);
	else
		execute_recursively(RB, NULL, b, b->top - find);
}

// void execute_rotate(t_stack *self, int n, char *op, char *reverse_op)
// {
// 	int	find;

// 	find = self->top;
// 	while (find >= 0 && self->vec[find] != n)
// 		find--;
// 	if (find < 0)
// 		return ;
// 	else if (find < self->top / 2)
// 		execute_recursively(reverse_op, NULL, self, find + 1);
// 	else
// 		execute_recursively(op, NULL, self, self->top - find);
// }
