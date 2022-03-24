/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:59:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 08:31:18 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *origin, t_stack *dest)
{
	if (origin->top == -1)
		return ;
	dest->vec[++dest->top] = origin->vec[origin->top--];
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top <= 0)
		return ;
	tmp = stack->vec[stack->top];
	stack->vec[stack->top] = stack->vec[stack->top - 1];
	stack->vec[stack->top - 1] = tmp;
}

void	rotate(t_stack *stack)
{
	unsigned int	i;
	int				tmp;

	i = stack->top + 1;
	tmp = stack->vec[stack->top];
	while (--i)
		stack->vec[i] = stack->vec[i - 1];
	stack->vec[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->vec[0];
	while (++i < stack->top)
		stack->vec[i] = stack->vec[i + 1];
	stack->vec[stack->top] = tmp;
}
