

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;


int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}



t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}


void	add_to_top(t_node *node, t_stack *stack)
{
	if (stack->top)
	{
		node->prev = stack->top;
		stack->top->next = node;
		stack->top = node;
	}
	else
	{
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

// sa: top ile top->prev’i değiştir (swap value ya da pointer)

// pb: detach_top(a) → attach_top(b, node)

// pa: detach_top(b) → attach_top(a, node)

// ra: detach_top(a) → attach_bottom(a, node)

// rra: detach_bottom(a) → attach_top(a, node)

void	sa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;

	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;

	tmp->prev = stack->top->prev;
	tmp->next = stack->top;

	if (stack->top->prev != NULL) //  ÖNCEKİ 2.NİN ALTINDAKİ SON ELEMAN MI KONTROLÜ
		stack->top->prev->next = tmp;
	else
		stack->bottom = tmp;
	stack->top->prev = tmp;
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp_b;

	if (!b->top)
		return ;

	tmp_b = b->top;
	if (tmp_b->prev)
	{
		b->top = tmp_b->prev;
		b->top->next = NULL;
		if (!b->top->prev)
			b->bottom = b->top;
	}
	else
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	tmp_b->prev = a->top;
	a->top->next = tmp_b;
	a->top = tmp_b;
	a->size++;
	b->size--;
}


void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp_a;

	tmp_a = a->top;
	a->top = tmp_a->prev;
	a->top->next = NULL;
	if (!a->top->prev)
		a->bottom = a->top;
	if (b->top)
	{
		tmp_a->prev = b->top;
		b->top->next = tmp_a;
	}
	else
	{
		tmp_a->prev = NULL;
		b->bottom = tmp_a;
	}
	b->top = tmp_a;
	b->size++;
	a->size--;
}

void	ra()
{
	
}

void	rra()
{
	
}

int	main(int c, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;
	i = 1;
	while (argv[i])
	{
		add_to_top(create_node(ft_atoi(argv[i])), &a);
		i++;
	}
	if (a.top)
	{
		while (a.top)
		{
			printf("%i\n", a.top->value);
			a.top = a.top->prev;
		}
	}

}
