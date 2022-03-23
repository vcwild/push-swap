/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 07:15:58 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/23 07:15:59 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute(char *op, t_stack *a, t_stack *b)
{
	if (ft_streq(op, PA))
		push(b, a);
	else if (ft_streq(op, PB))
		push(a, b);
	else if (ft_streq(op, SA))
		swap(a);
	else if (ft_streq(op, SB))
		swap(b);
	else if (ft_streq(op, RA))
		rotate(a);
	else if (ft_streq(op, RB))
		rotate(b);
	else if (ft_streq(op, RRA))
		reverse_rotate(a);
	else if (ft_streq(op, RRB))
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
	return (0);
}

static int	small_sort(t_stack *a)
{
	if (a->vec[0] > a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] < a->vec[0])
		execute(SA, a, NULL);
	else if (a->vec[0] < a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
	{
		execute(SA, a, NULL);
		execute(RRA, a, NULL);
	}
	else if (a->vec[0] > a->vec[1] && a->vec[1] < a->vec[2] && a->vec[2] > a->vec[0])
		execute(RA, a, NULL);
	else if (a->vec[0] < a->vec[1] && a->vec[1] > a->vec[2] && a->vec[2] < a->vec[0])
	{
		execute(SA, a, NULL);
		execute(RA, a, NULL);
	}
	else if (a->vec[0] < a->vec[1] && a->vec[1] > a->vec[2] && a->vec[2] > a->vec[0])
		execute(RRA, a, NULL);
	return (0);
}

void	execute_recursively(char *op, t_stack *a, t_stack *b, int times)
{
	if (times <= 0)
		return ;
	execute(op, a, b);
	execute_recursively(op, a, b, times - 1);
}


void	smart_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->vec[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		execute_recursively(RRA, a, NULL, find + 1);
	else
		execute_recursively(RA, a, NULL, a->top - find);
}

int	closest_above(t_stack *a, int n)
{
	int	highest_num_found;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	highest_num_found = max(a);
	while (i <= a->top)
	{
		if (a->vec[i] > n && a->vec[i] < highest_num_found)
			highest_num_found = a->vec[i];
		i++;
	}
	return (highest_num_found);
}

static void	put_top_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	num_to_move;

	top_b = b->vec[b->top];
	num_to_move = closest_above(a, top_b);
	if (num_to_move == top_b)
		num_to_move = min(a);
	smart_rotate_a(a, num_to_move);
	execute(PA, a, b);
}

static int	small_sort_complex(t_stack *a, t_stack *b)
{
	execute_recursively(PB, a, b, a->top - 2);
	small_sort(a);
	while (b->top >= 0)
		put_top_in_position(a, b);
	smart_rotate_a(a, 0);
	return (0);
}

int	handle_small_complexity(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		return (execute(SA, a, NULL));
	if (a->top == 2)
		return (small_sort(a));
	return (small_sort_complex(a, b));
}

void	handle_sort(t_stack *stack)
{
	t_stack alt_stack;

	alt_stack = (t_stack)
	{
		.top = -1,
		.vec = (int *)ft_calloc(STACK_MAX_SIZE, sizeof(int))
	};
	if (stack->top < STACK_SIMPLE_SORT_MAX_MEMBERS)
		handle_small_complexity(stack, &alt_stack);
	// else
	// 	sort_complex(stack, &alt_stack);
	free(alt_stack.vec);
}
