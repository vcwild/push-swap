/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:59:45 by vwildner          #+#    #+#             */
/*   Updated: 2022/03/15 22:39:42 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *origin, t_stack *dest)
{
	if (origin->top == -1)
		return ;
	dest->vec[++dest->top] = origin->vec[origin->top--];
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top <= 0)
		return ;
	tmp = stack->vec[stack->top];
	stack->vec[stack->top] = stack->vec[stack->top - 1];
	stack->vec[stack->top - 1] = tmp;
}

void	rotate(t_stack *stack)
{
	unsigned int	i;
	int				tmp;

	i = stack->top + 1;
	tmp = stack->vec[stack->top];
	while (--i)
		stack->vec[i] = stack->vec[i - 1];
	stack->vec[0] = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stack->vec[0];
	while (++i < stack->top)
		stack->vec[i] = stack->vec[i + 1];
	stack->vec[stack->top] = tmp;
}

void	exec_op(t_stack *a, t_stack *b, char *op_name)
{
	if (ft_strncmp(op_name, "pa", 2) == 0)
		return (push(a, b));
	if (ft_strncmp(op_name, "pb", 2) == 0)
		return (push(b, a));
	if (ft_strncmp(op_name, "sa", 2) == 0)
		return (swap(a));
	if (ft_strncmp(op_name, "sb", 2) == 0)
		return (swap(b));
	if (ft_strncmp(op_name, "ra", 2) == 0)
		return (rotate(a));
	if (ft_strncmp(op_name, "rb", 2) == 0)
		return (rotate(b));
	if (ft_strncmp(op_name, "rra", 3) == 0)
		return (reverse_rotate(a));
	if (ft_strncmp(op_name, "rrb", 3) == 0)
		return (reverse_rotate(b));
	ft_perror("Invalid operation name\n");
}
