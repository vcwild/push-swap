/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:01:06 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 12:01:07 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	asked_for_help(const char *arg)
{
	return ((ft_strncmp(arg, "-h", 2) == 0)
		|| (ft_strncmp(arg, "--help", 6) == 0));
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	if (argc < 2)
		die(&stack, "", 0);
	if (asked_for_help(argv[1]))
	{
		write(STDOUT_FILENO, "Usage: ./push_swap \"<numbers>\"\n", 31);
		die(&stack, "", 0);
	}
	if (handle_parse_args(&stack, argc, argv))
		die(&stack, "Parse args failed", 3);
	if (is_reverse_sorted(&stack) || stack.top <= 0)
		die(&stack, "", 0);
	if (normalize(stack.vec, stack.top + 1))
		die(&stack, "Normalization failed", 4);
	if (handle_sort(&stack))
		die(&stack, "Sorting failed", 5);
	die(&stack, "", 0);
}
