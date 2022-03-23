/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:16:07 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 07:16:09 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_vec(int *vec, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		ft_swap(&vec[i++], &vec[size - 1], sizeof(int));
		reverse_vec(vec, size - 1);
	}
	i = 0;
}

bool	is_sorted(t_stack *self)
{
	int	iter;

	iter = -1;
	while (++iter < self->top)
	{
		if (self->vec[iter] > self->vec[iter + 1])
			return (false);
	}
	return (true);
}

bool	ft_streq(const char *s1, const char *s2)
{
	return (!(ft_strncmp(s1, s2, ft_strlen(s2) + 1)));
}
