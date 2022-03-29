/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:59:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 18:41:04 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *origin, t_stack *dest)
{
	if (origin->top == -1)
		return ;
	dest->vec[++dest->top] = origin->vec[origin->top--];
}

void	swap(t_stack *self)
{
	int	tmp;

	if (self->top <= 0)
		return ;
	tmp = self->vec[self->top];
	self->vec[self->top] = self->vec[self->top - 1];
	self->vec[self->top - 1] = tmp;
}

void	rotate(t_stack *self)
{
	unsigned int	i;
	int				tmp;

	i = self->top + 1;
	tmp = self->vec[self->top];
	while (--i)
		self->vec[i] = self->vec[i - 1];
	self->vec[0] = tmp;
}

void	reverse_rotate(t_stack *self)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = self->vec[0];
	while (++i < self->top)
		self->vec[i] = self->vec[i + 1];
	self->vec[self->top] = tmp;
}
