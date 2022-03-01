/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slashcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:45:01 by vwildner          #+#    #+#             */
/*   Updated: 2022/02/11 20:29:56 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_slashcat(const char *origin, const char *other)
{
	char	*cat;
	int		i;

	cat = ft_calloc(ft_strlen(origin) + ft_strlen(other) + 2, sizeof(char));
	if (cat == NULL || origin == NULL || other == NULL)
		return (NULL);
	i = -1;
	while (*origin)
	{
		cat[++i] = *origin;
		origin++;
	}
	i++;
	cat[i++] = '/';
	while (*other)
	{
		cat[i++] = *other;
		other++;
	}
	cat[i] = '\0';
	return (cat);
}
