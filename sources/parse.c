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

static int	parse_single_arg(t_stack *self, char *arg)
{
	printf("Parsing single arg: %s\n", arg);
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
		{
			printf("check_int\n");
			status = 1;
		}
		if (atoi_to_buff(args_str[i], &curr_num))
		{
			printf("atoi\n");
			status = 2;
		}
		if (check_duplicate_number(self, &curr_num))
		{
			printf("check_duplicate_number\n");
			status = 3;
		}
		else
			self->vec[++self->top] = curr_num;
		printf("self->vec[%i]: %d\n", self->top, curr_num);
	}
	free_vec((void **)args_str);
	return (status);
}

static int parse_multi_args(t_stack *self, int argc, char *argv[])
{
	printf("Parsing multi args\n");

	return (0);
}

int handle_parse_args(t_stack *self, int argc, char *argv[])
{
	if (argc == 2)
	{
		if (parse_single_arg(self, argv[1]))
			return (1);
		return (0);
	}
	if (!parse_multi_args(self, argc, argv))
		return (2);
	return (0);
}
