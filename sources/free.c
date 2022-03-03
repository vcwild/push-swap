#include "push_swap.h"

void	free_vec(void **vec)
{
	size_t	i;

	i = 0;
	while (vec[i])
		free(vec[i++]);
	free(vec);
}
