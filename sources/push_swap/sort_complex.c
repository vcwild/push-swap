/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:15:58 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 13:00:50 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	set_chunks(int size, int chunk_size)
{
	size_t	chunk;

	chunk = size / chunk_size + 1;
	return (chunk);
}

static void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_closest_index_from_b_to_top(b);
		execute_rotate_closest_above_and_push(a, b);
	}
}

void	complex_sort(t_stack *a, t_stack *b)
{
	size_t			chunks;
	size_t			step;
	int				n_elements;
	int				min_index;
	int				max_index;

	n_elements = a->top + 1;
	chunks = set_chunks(n_elements, 50);
	step = (n_elements) / chunks;
	max_index = max(a);
	while (chunks >= 1)
	{
		if (chunks == 1)
			min_index = min(a);
		else
			min_index = max_index - step + 1;
		move_chunk_to_top(a, b, min_index, max_index);
		sort_chunk(a, b);
		max_index = min_index - 1;
		chunks--;
	}
	execute_rotate(a, min(a), RA, RRA);
}
