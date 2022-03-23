/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:48:41 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 19:23:35 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: remove `!` from parse_multi_args if you want to implement this

static int	asked_for_help(const char *arg)
{
	if ((ft_strncmp(arg, "-h", 2) == 0)
		|| (ft_strncmp(arg, "--help", 6) == 0))
	{
		write(STDOUT_FILENO, "Usage: ./push_swap \"[numbers]\"\n", 31);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	if (argc != 2)
		die(&stack, "Invalid number of arguments provided", 1);
	if (asked_for_help(argv[1]))
		die(&stack, "", 0);
	if (handle_parse_args(&stack, argc, argv))
		die(&stack, "Parse args failed", 3);
	if (is_sorted(&stack) || stack.top <= 0)
		die(&stack, "", 4);
	if (normalize(stack.vec, stack.top + 1))
		die(&stack, "Normalization failed", 5);
	handle_sort(&stack);
		// die(&stack, "Sort failed", 6);
	// for (int i = 0; i < 5; i++)
	// 	printf("origin[%i]: %d \n", i, stack.vec[i]);
	free(stack.vec);
}
