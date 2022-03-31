/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:17:13 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/30 21:54:13 by vwildner         ###   ########.fr       */
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

/**
 * @brief Frees the entire memory allocated for a matrix
 *
 * @param vec The matrix to be freed
 */
static void	free_vec(void **vec)
{
	size_t	i;

	i = 0;
	while (vec[i])
		free(vec[i++]);
	free(vec);
}

/**
 * @brief Parses a string of numbers separated by spaces and returns an array
 *
 * @param self The instance of the stack to push the numbers to
 * @param arg The input string to parse
 * @return int Returns 0 on success, and a positive integer on error
 */
static int	parse_single_arg(t_stack *self, char *arg)
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
	free_vec((void **)args_str);
	return (status);
}

static int	parse_multiple_args(t_stack *self, int argc, char *argv[])
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	while (++i < argc && !status)
		status = parse_single_arg(self, argv[i]);
	reverse_vec(self->vec, self->top + 1);
	return (status);
}

int	handle_parse_args(t_stack *self, int argc, char *argv[])
{
	if (parse_multiple_args(self, argc, argv))
		return (1);
	return (0);
}
