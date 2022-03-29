/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:50:55 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 18:39:49 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_min(int *vec, size_t len)
{
	int	min;

	if (len == 1)
		return (vec[0]);
	min = _min(vec, len - 1);
	if (min > vec[len - 1])
		min = vec[len - 1];
	return (min);
}

int	min(t_stack *self)
{
	return (_min(self->vec, self->top + 1));
}

static int	_max(int *vec, size_t len)
{
	int	max;

	if (len == 1)
		return (vec[0]);
	max = _max(vec, len - 1);
	if (vec[len - 1] > max)
		max = vec[len - 1];
	return (max);
}

int	max(t_stack *self)
{
	return (_max(self->vec, self->top + 1));
}
