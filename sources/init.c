#include "push_swap.h"

int		init_stack(t_stack *self)
{
	self->top = -1;
	self->vec = (int *)calloc(STACK_MAX_SIZE, sizeof(int));
	if (!(self->vec))
		return (1);
	return (0);
}
