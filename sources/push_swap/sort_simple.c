/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:33:40 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/26 18:58:24 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_sort(t_stack *a)
{
	if (a->vec[0] > a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] < a->vec[0])
		execute(SA, a, NULL);
	else if (a->vec[0] < a->vec[1]
		&& a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
	{
		execute(SA, a, NULL);
		execute(RRA, a, NULL);
	}
	else if (a->vec[0] > a->vec[1]
		&& a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
		execute(RA, a, NULL);
	else if (a->vec[0] < a->vec[1]
		&& a->vec[1] > a->vec[2] && a->vec[2] < a->vec[0])
	{
		execute(SA, a, NULL);
		execute(RA, a, NULL);
	}
	else if (a->vec[0] < a->vec[1]
		&& a->vec[1] > a->vec[2] && a->vec[2] > a->vec[0])
		execute(RRA, a, NULL);
	return (0);
}

static void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	num_to_move;

	top_b = b->vec[b->top];
	num_to_move = find_closest_above(a, top_b);
	if (num_to_move == top_b)
		num_to_move = min(a);
	execute_rotate_a(a, num_to_move);
	execute(PA, a, b);
}

int	simple_sort_complete(t_stack *a, t_stack *b)
{
	execute_recursively(PB, a, b, a->top - 2);
	simple_sort(a);
	while (b->top >= 0)
		put_top_in_position(a, b);
	execute_rotate_a(a, 0);
	return (0);
}
