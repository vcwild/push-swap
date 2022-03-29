/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:18:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:18:14 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *v1, void *v2, size_t size)
{
	void	*temp;

	temp = malloc(size);
	ft_memcpy(temp, v1, size);
	ft_memcpy(v1, v2, size);
	ft_memcpy(v2, temp, size);
	free(temp);
}
