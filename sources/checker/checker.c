/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:03:20 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/29 20:36:48 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	message_and_exit(t_stack *self, char **ops, int status)
{
	if (self)
		free(self->vec);
	if (ops)
		free_vec((void **)ops);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(status);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		status;
	char	**instructions;

	stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	status = 0;
	instructions = NULL;
	if (handle_parse_args(&stack, argc, argv))
		die(&stack, "", 0);
	status = get_instructions(&instructions);
	if (status)
		message_and_exit(&stack, instructions, status);
	execute_instructions(instructions, &stack);
	free_vec((void **)instructions);
	free(stack.vec);
	return (status);
}
