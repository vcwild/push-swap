/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:15:58 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/25 00:52:01 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (between(a->vec[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (between(a->vec[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack *a, int min, int max)
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

void move_chunk_to_top(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		execute(PB, a, b);
		size--;
	}
}

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (stack->vec[i] != n && i >= 0)
		i--;
	return (i);
}

void	move_min_or_max_to_top(t_stack *b)
{
	int	i;
	int	index[2];

	index[0] = _index(b, min(b));
	index[1] = _index(b, max(b));
	if (index[0] < b->top - index[1])
		i = index[0];
	else
		i = index[1];
	execute_rotate_b(b, b->vec[i]);
}

void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->vec[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	execute_rotate_a(a, to_move);
	execute(PA, a, b);
}


void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_min_or_max_to_top(b);
		put_in_position(a, b);
	}
}

size_t	set_chunks(int size, int chunk_size)
{
	size_t	chunk;

	chunk = size / chunk_size + 1;
	return (chunk);
}

int set_min_index(t_stack *self, size_t chunks, int step)
{
	if (chunks == 1)
		return(min(self));
	return (max(self) - step + 1);
}

void complex_sort(t_stack *a, t_stack *b)
{
	size_t			chunks;
	size_t			step;
	unsigned int	n_elements;
	int				min_index;
	int				max_index;

	n_elements = a->top + 1;
	chunks = set_chunks(n_elements, 50);
	step = (n_elements) / chunks;
	while (chunks > 0)
	{
		min_index = set_min_index(a, chunks, step);
		max_index = max(a);
		move_chunk_to_top(a, b, min_index, max_index);
		sort_chunk(a, b);
		max_index = min_index - 1;
		chunks--;
	}
	execute_rotate_a(a, min(a));
}
