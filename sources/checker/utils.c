/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:26:25 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 16:05:30 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	invalid_instruction(char *op)
{
	if (not_strncmp(op, SA))
		return (false);
	else if (not_strncmp(op, SB))
		return (false);
	else if (not_strncmp(op, SS))
		return (false);
	else if (not_strncmp(op, PA))
		return (false);
	else if (not_strncmp(op, PB))
		return (false);
	else if (not_strncmp(op, RA))
		return (false);
	else if (not_strncmp(op, RB))
		return (false);
	else if (not_strncmp(op, RR))
		return (false);
	else if (not_strncmp(op, RRA))
		return (false);
	else if (not_strncmp(op, RRB))
		return (false);
	else if (not_strncmp(op, RRR))
		return (false);
	return (true);
}

static int	heap_set(char ***instructions, char **buffer, int i)
{
	char			**tmp;
	static size_t	in_size;

	tmp = malloc((in_size + i + 1) * sizeof(*tmp));
	if (!tmp)
		return (1);
	if (in_size)
	{
		ft_memcpy(tmp, *instructions, in_size * sizeof(*tmp));
		free(*instructions);
	}
	ft_memcpy(tmp + in_size, buffer, i * sizeof(*tmp));
	tmp[in_size + i] = NULL;
	in_size += i;
	*instructions = tmp;
	return (0);
}

int	get_instructions(char ***instructions)
{
	int		i;
	int		status;
	char	*buffer[INSTRUCTIONS_BUFFER_SIZE];
	char	*op;

	i = 0;
	status = 0;
	while (!status && (get_next_line(STDIN_FILENO, &op) > 0))
	{
		if (invalid_instruction(op))
			status = 1;
		else
		{
			buffer[i++] = op;
			if (i == INSTRUCTIONS_BUFFER_SIZE)
			{
				heap_set(instructions, buffer, i);
				ft_bzero(buffer, INSTRUCTIONS_BUFFER_SIZE);
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i);
	free(op);
	return (status);
}
