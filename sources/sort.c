/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:38:09 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/16 22:33:16 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_exec_op(t_stack *a, t_stack *b, char *op_name)
{
	exec_op(a, b, op_name);
	write(STDOUT_FILENO, op_name, ft_strlen(op_name));
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

int	handle_three_elements(t_stack *a)
{
	if (a->vec[0] > a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] < a->vec[0])
		return (handle_exec_op(a, NULL, "sa"));
	if (a->vec[0] < a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
	{
		handle_exec_op(a, NULL, "sa");
		return (handle_exec_op(a, NULL, "rra"));
	}
	if (a->vec[0] > a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
		return (handle_exec_op(a, NULL, "ra"));
	if (a->vec[0] < a->vec[1] && a->vec[1] > a->vec[2] && a->vec[2] < a->vec[0])
	{
		handle_exec_op(a, NULL, "sa");
		return (handle_exec_op(a, NULL, "ra"));
	}
	if (a->vec[0] < a->vec[1] && a->vec[1] > a->vec[2] && a->vec[2] > a->vec[0])
		return (handle_exec_op(a, NULL, "rra"));
	// ft_perror("Unable to handle `three elements state`\n");
	return (0);
}

void exec_op_recursively(t_stack *a, t_stack *b, char *op_name, int times)
{
	if (times <= 0)
		return ;
	handle_exec_op(a, b, op_name);
	exec_op_recursively(a, b, op_name, times - 1);
}

void smart_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->vec[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		exec_op_recursively(a, NULL, "rra", find + 1);
	else
		exec_op_recursively(a, NULL, "ra", a->top - find);
}

int	closest_above(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->vec[i] > n && a->vec[i] < k)
			k = a->vec[i];
		i++;
	}
	return (k);
}

void move_to_top(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->vec[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b)
		to_move = min(a);
	smart_rotate_a(a, to_move);
	handle_exec_op(a, b, "pa");
}

int	handle_simple_default(t_stack *a, t_stack *b)
{
	exec_op_recursively(a, b, "pb", a->top - 2);
	handle_three_elements(a);
	while (b->top >= 0)
		move_to_top(a, b);
	smart_rotate_a(a, 0);
	return (0);
}

int	simple_sort(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		return (handle_exec_op(a, NULL, "sa"));
	if (a->top == 2)
		return (handle_three_elements(a));
	return (handle_simple_default(a, b));
}

int complex_sort(t_stack *a, t_stack *b)
{
	b->vec = NULL;
	die(a, "Not implemented yet", 28);
	return (-1);
}

int	sort_stack(t_stack *a, t_stack *b)
{
	if (a->top < STACK_SIMPLE_SORT_MAX_MEMBERS)
		return (simple_sort(a, b));
	return (complex_sort(a, b));
}

int	handle_sort_stack(t_stack *stack)
{
	t_stack alt_stack;
	int	status;

	status = 0;
	alt_stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	status = sort_stack(stack, &alt_stack);
	free(alt_stack.vec);
	return (status);
}
