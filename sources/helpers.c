#include "push_swap.h"

static void swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse_vec(int *vec, size_t size)
{
	static size_t	i;

	if (i < size)
	{
		swap(&vec[i++], &vec[size - 1]);
		reverse_vec(vec, size - 1);
	}
	i = 0;
}

// ARR = [0, 2, 3, 4] i = 0
// ARR[0] -> 0 -> 2
// ARR[1] -> 2 -> 0
// size = 4
// size = 3



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


// int main(void)
// {
// 	int arr[] = {0, 1, 2, 3};

// 	reverse_vec(arr, ft_strlen(arr));
// 	int i;
// 	while (i < ft_strlen(arr))
// 		printf("%i\n", arr[i]);
// }
