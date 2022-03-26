/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:41:09 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/26 19:05:39 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_closest_index_from_a_to_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];

	index[0] = find_from_top(a, min, max);
	index[1] = find_from_bottom(a, min, max);
	if (index[0] < a->top - index[1])
		i = index[0];
	else
		i = index[1];
	execute_rotate_a(a, a->vec[i]);
}

void	move_chunk_to_top(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max + 1;
	while (size--)
	{
		move_closest_index_from_a_to_top(a, min, max);
		execute(PB, a, b);
	}
}

static int	find_index(t_stack *stack, int pos)
{
	int	i;

	i = stack->top;
	while (stack->vec[i] != pos && i >= 0)
		i--;
	return (i);
}

void	move_closest_index_from_b_to_top(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = find_index(b, min(b));
	index[1] = find_index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	execute_rotate_b(b, b->vec[i]);
}
