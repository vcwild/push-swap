bool	ft_streq(const char *s1, const char *s2)
{
	return (!(ft_strncmp(s1, s2, ft_strlen(s2) + 1)));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n-- && dst != src)
		*d++ = *s++;
	return (dst);
}


static bool	invalid_instruction(char *op)
{
	if (ft_streq(op, "sa"))
		return (false);
	else if (ft_streq(op, "sb"))
		return (false);
	else if (ft_streq(op, "ss"))
		return (false);
	else if (ft_streq(op, "pa"))
		return (false);
	else if (ft_streq(op, "pb"))
		return (false);
	else if (ft_streq(op, "ra"))
		return (false);
	else if (ft_streq(op, "rb"))
		return (false);
	else if (ft_streq(op, "rr"))
		return (false);
	else if (ft_streq(op, "rra"))
		return (false);
	else if (ft_streq(op, "rrb"))
		return (false);
	else if (ft_streq(op, "rrr"))
		return (false);
	return (true);
}

static int	heap_set(char ***instructions, char **buffer, int i)
{
	char			**tmp;
	static size_t	in_size;

	tmp = malloc((in_size + i + 1) * sizeof(*tmp));
	if (!tmp)
		return (1);
	if (in_size)
	{
		ft_memcpy(tmp, *instructions, in_size * sizeof(*tmp));
		free(*instructions);
	}
	ft_memcpy(tmp + in_size, buffer, i * sizeof(*tmp));
	tmp[in_size + i] = NULL;
	in_size += i;
	*instructions = tmp;
	return (0);
}

int	get_instructions(char ***instructions)
{
	int		i;
	int		status;
	char	*buffer[INSTRUCTIONS_BUFFER_SIZE];
	char	*op;

	i = 0;
	status = 0;
	while (!status && (get_next_line(STDIN_FILENO, &op) > 0))
	{
		if (invalid_instruction(op))
			status = 1;
		else
		{
			buffer[i++] = op;
			if (i == INSTRUCTIONS_BUFFER_SIZE)
			{
				heap_set(instructions, buffer, i);
				ft_bzero(buffer, INSTRUCTIONS_BUFFER_SIZE);
				i = 0;
			}
		}
	}
	heap_set(instructions, buffer, i);
	free(op);
	return (status);
}

t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!(stack))
		return (NULL);
	stack->array = malloc(size * sizeof(*(stack->array)));
	if (!(stack->array))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

bool	validate_int(char *elem)
{
	bool			is_int;
	unsigned int	i;
	unsigned int	cm;

	i = 0;
	cm = 0;
	is_int = true;
	while (elem[i] && is_int)
	{
		if (elem[i] == '-' && cm < 1)
			cm++;
		else if (!ft_isdigit(elem[i]))
			is_int = false;
		i++;
	}
	return (!is_int);
}

int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE);
	while (array[j] && !status)
	{
		if (validate_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (already_exists(n, stack))
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

t_stack	*get_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(STACK_BUFFER);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
	{
		free_stack(stack);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(status);
	}
	reverse_array(stack->array, stack->top + 1);
	return (stack);
}


int	main(int argc, char *argv[])
{
	int		status;
	t_stack	*stack;
	char	**instructions;

	status = 0;
	instructions = NULL;
	stack = get_stack(argc - 1, &argv[1]);
	status = get_instructions(&instructions);
	if (status)
		message_and_exit(stack, instructions, status);
	execute(instructions, stack);
	free_array((void **)instructions);
	free_stack(stack);
	return (status);
}
