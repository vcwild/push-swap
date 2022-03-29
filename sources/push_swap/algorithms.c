/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:58:06 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insertion_sort(int *vec, size_t size)
{
	int	index;
	int	iter;

	iter = -1;
	while (++iter < (int)(size - 1))
	{
		index = iter + 1;
		while (--index >= 0 && vec[index] > vec[index + 1])
			ft_swap(&vec[index], &vec[index + 1], sizeof(int));
	}
}

static void	relabel_vec_with_pos(int *reference,
		int *vec, int *buffer, int size)
{
	int		i;
	size_t	pos;

	i = 0;
	while (i <= size - 1)
	{
		pos = 0;
		while (buffer[pos] != reference[i])
			pos++;
		vec[i++] = pos;
	}
}

int	normalize(int *origin, size_t size)
{
	int		*copy;
	int		*vec;

	vec = (int *)ft_calloc(size, sizeof(int));
	copy = (int *)ft_calloc(size, sizeof(int));
	if (!vec || !copy)
		return (1);
	ft_memcpy(copy, origin, size * sizeof(*copy));
	insertion_sort(copy, size);
	relabel_vec_with_pos(origin, vec, copy, (int)size);
	ft_memcpy(origin, vec, size * sizeof(*vec));
	free(copy);
	free(vec);
	return (0);
}
