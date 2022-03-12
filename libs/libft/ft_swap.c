#include "libft.h"

void	ft_swap(void *v1, void *v2, size_t size)
{
	void *temp;

	temp = malloc(size);
	ft_memcpy(temp, v1, size);
	ft_memcpy(v1, v2, size);
	ft_memcpy(v2, temp, size);
	free(temp);
}
