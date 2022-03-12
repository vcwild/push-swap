#include "push_swap.h"

void reverse_vec(int *vec, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		ft_swap(&vec[i++], &vec[size - 1], sizeof(int));
		reverse_vec(vec, size - 1);
	}
	i = 0;
}

bool	is_sorted(t_stack *self)
{
	int	iter;

	iter = -1;
	while (++iter < self->top)
	{
		if (self->vec[iter] > self->vec[iter + 1])
			return (false);
	}
	return (true);
}
