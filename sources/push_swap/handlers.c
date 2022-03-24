/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:35:31 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 19:31:22 by vwildner         ###   ########.fr       */
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

static int handle_high_complexity(t_stack *a, t_stack *b)
{
	complex_sort(a, b);
	return (0);
}

void	handle_sort(t_stack *stack)
{
	t_stack alt_stack;

	alt_stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	if (stack->top < STACK_SIMPLE_SORT_MAX_MEMBERS)
		handle_simple_complexity(stack, &alt_stack);
	else
		handle_high_complexity(stack, &alt_stack);
	free(alt_stack.vec);
}
