/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:53:18 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/26 18:58:38 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_above(t_stack *a, int n)
{
	int	highest_num_found;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	highest_num_found = max(a);
	while (i <= a->top)
	{
		if (a->vec[i] > n && a->vec[i] < highest_num_found)
			highest_num_found = a->vec[i];
		i++;
	}
	return (highest_num_found);
}

static int	is_between(int n, int min_index, int max_index)
{
	return (n >= min_index && n <= max_index);
}

int	find_from_top(t_stack *a, int min_index, int max_index)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (is_between(a->vec[i], min_index, max_index))
			return (i);
		i++;
	}
	return (-1);
}

int	find_from_bottom(t_stack *a, int min_index, int max_index)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (is_between(a->vec[i], min_index, max_index))
			return (i);
		i--;
	}
	return (-1);
}
