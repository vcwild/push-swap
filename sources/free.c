/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:16:50 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 07:16:52 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_vec(void **vec)
{
	size_t	i;

	i = 0;
	while (vec[i])
		free(vec[i++]);
	free(vec);
}
