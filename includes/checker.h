#ifndef CHECKER_H
# define CHECKER_H

# define INSTRUCTIONS_BUFFER_SIZE 4096

#include "push_swap.h"

void	free_stack(t_stack *self);

int		get_instructions(char ***instructions);
int		execute_instructions(char **instructions, t_stack *stack);
t_stack	*initialize(void);

#endif
