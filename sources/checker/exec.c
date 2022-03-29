/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:54:59 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:36:19 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, SA) || ft_streq(op, SS))
		swap(a);
	if (ft_streq(op, SB) || ft_streq(op, SS))
		swap(b);
}

static void	push_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, PA))
		push(b, a);
	else if (ft_streq(op, PB))
		push(a, b);
}

static void	rotate_stacks(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, RA) || ft_streq(op, RR))
		rotate(a);
	if (ft_streq(op, RB) || ft_streq(op, RR))
		rotate(b);
	if (ft_streq(op, RRA) || ft_streq(op, RRR))
		reverse_rotate(a);
	if (ft_streq(op, RRB) || ft_streq(op, RRR))
		reverse_rotate(b);
}

int	execute_instructions(char **instructions, t_stack *a)
{
	t_stack	b;

	b = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	while (*instructions)
	{
		if (*instructions[0] == 's')
			swap_stacks(*instructions, a, &b);
		else if (*instructions[0] == 'p')
			push_stacks(*instructions, a, &b);
		else
			rotate_stacks(*instructions, a, &b);
		instructions++;
	}
	if (is_sorted(a) || b.top > -1)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	free(b.vec);
	return (0);
}
