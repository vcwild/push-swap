/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:21:11 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 07:21:20 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *self)
{
	self->top = -1;
	self->vec = (int *)calloc(STACK_MAX_SIZE, sizeof(int));
	if (!(self->vec))
		return (1);
	return (0);
}
