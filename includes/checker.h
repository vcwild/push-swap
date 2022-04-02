/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwildner <vwildner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:37:07 by vwildner          #+#    #+#             */
/*   Updated: 2022/04/02 14:56:52 by vwildner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INSTRUCTIONS_BUFFER_SIZE 4096

# include "push_swap.h"

int		get_instructions(char ***instructions);
int		execute_instructions(char **instructions, t_stack *stack);
t_stack	*initialize(void);

#endif
