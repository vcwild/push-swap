/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:35:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/30 22:14:45 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_simple_complexity(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		return (execute(SA, a, NULL));
	if (a->top == 2)
		return (simple_sort(a));
	return (simple_sort_complete(a, b));
}

static int	handle_high_complexity(t_stack *a, t_stack *b)
{
	complex_sort(a, b);
	return (0);
}

int	handle_sort(t_stack *self)
{
	t_stack	other;
	int		status;

	other = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	if (self->top < STACK_SIMPLE_SORT_MAX_MEMBERS)
		status = handle_simple_complexity(self, &other);
	else
		status = handle_high_complexity(self, &other);
	free(other.vec);
	return (status);
}
