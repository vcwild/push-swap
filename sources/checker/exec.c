/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:54:59 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 16:29:25 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_stacks(char *op, t_stack *a, t_stack *b)
{
	if (not_strncmp(op, SA) || not_strncmp(op, SS))
		swap(a);
	if (not_strncmp(op, SB) || not_strncmp(op, SS))
		swap(b);
}

static void	push_stacks(char *op, t_stack *a, t_stack *b)
{
	if (not_strncmp(op, PA))
		push(b, a);
	else if (not_strncmp(op, PB))
		push(a, b);
}

static void	rotate_stacks(char *op, t_stack *a, t_stack *b)
{
	if (not_strncmp(op, RA) || not_strncmp(op, RR))
		rotate(a);
	if (not_strncmp(op, RB) || not_strncmp(op, RR))
		rotate(b);
	if (not_strncmp(op, RRA) || not_strncmp(op, RRR))
		reverse_rotate(a);
	if (not_strncmp(op, RRB) || not_strncmp(op, RRR))
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
	if (!is_reverse_sorted(a) || b.top > -1)
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	else
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	free(b.vec);
	return (0);
}
