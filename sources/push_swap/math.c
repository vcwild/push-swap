/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:50:55 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/15 22:50:57 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_min(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _min(array, len - 1);
	if (array[len - 1] < m)
		m = array[len - 1];
	return (m);
}

int	min(t_stack *stack)
{
	return (_min(stack->vec, stack->top + 1));
}

static int	_max(int *array, size_t len)
{
	int	m;

	if (len == 1)
		return (array[0]);
	m = _max(array, len - 1);
	if (array[len - 1] > m)
		m = array[len - 1];
	return (m);
}

int	max(t_stack *stack)
{
	return (_max(stack->vec, stack->top + 1));
}
