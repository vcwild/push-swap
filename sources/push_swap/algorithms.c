/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:58:06 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/26 17:09:49 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(int *vec, size_t size)
{
	int				index;
	unsigned int	iter;
	int				tmp;

	iter = 1;
	while (iter < size)
	{
		index = iter - 1;
		tmp = vec[iter++];
		while (index >= 0 && vec[index + 1] < vec[index])
		{
			vec[index + 1] = vec[index];
			vec[index--] = tmp;
		}
	}
}

static void	isort_copy(int *origin, int *buffer, size_t size)
{
	ft_memcpy(buffer, origin, size * sizeof(*buffer));
	insertion_sort(buffer, size);
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
	isort_copy(origin, copy, size);
	relabel_vec_with_pos(origin, vec, copy, (int)size);
	ft_memcpy(origin, vec, size * sizeof(*vec));
	free(copy);
	free(vec);
	return (0);
}
