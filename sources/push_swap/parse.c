/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:17:13 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/25 00:53:59 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	atoi_to_buff(const char *str, int *buff)
{
	int		is_negative;

	*buff = 0;
	is_negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			is_negative = 1;
	while (*str >= '0' && *str <= '9')
	{
		*buff = *buff * 10 - (*str++ - '0');
		if (*buff > 0 || (*buff == INT_MIN && is_negative < 0))
			return (true);
	}
	*buff *= is_negative;
	return (false);
}

int	parse_single_arg(t_stack *self, char *arg)
{
	char			**args_str;
	int				curr_num;
	int				status;
	int				i;

	status = 0;
	i = -1;
	args_str = ft_split(arg, ' ');
	while (args_str[++i] && !status)
	{
		if (check_int(args_str[i]))
			status = 1;
		if (atoi_to_buff(args_str[i], &curr_num))
			status = 2;
		if (check_duplicate_number(self, &curr_num))
			status = 3;
		else
			self->vec[++self->top] = curr_num;
	}
	reverse_vec(self->vec, self->top + 1);
	free_vec((void **)args_str);
	return (status);
}

int	handle_parse_args(t_stack *self, int argc, char *argv[])
{
	if (argc == 2)
	{
		if (parse_single_arg(self, argv[1]))
			return (1);
		return (0);
	}
	return (1);
}
