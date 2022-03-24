/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:15:58 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 19:36:32 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void complex_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->top;
	j = b->top;
	while (i > 0 && j > 0)
	{
		i--;
		j--;
	}
}
