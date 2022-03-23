/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:16:34 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 07:16:36 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_duplicate_number(t_stack *self, int *num)
{
	int	pos;

	pos = self->top;
	while (pos >= 0)
	{
		if (self->vec[pos] == *num)
			return (true);
		pos--;
	}
	return (false);
}

bool	check_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}
