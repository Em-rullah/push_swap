
#include "main.h"

void	init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

void	push_to_top(t_stack *a, t_node *min, int *counter)
{
	t_node	*tmp;
	int		count;
	int		min_i;

	if (min->value == a->top->value)
		return ;
	tmp = a->top;
	count = 0;
	min_i = 0;
	while (tmp)
	{
		if (min == tmp)
			break ;
		min_i++;
		tmp = tmp->prev;
	}
	if (min_i <= a->size / 2)
	{
		while (min_i--)
			ra(a, counter);
	}
	else
	{
		count = a->size - min_i;
		while (count--)
			rra(a, counter);
	}
}

void	find_put_smallest(t_stack *a, int *counter)
{
	int		size;
	t_node	*tmp;

	size = a->size;
	tmp = a->top;
	while (size)
	{
		if (tmp->index == 0)
		{
			push_to_top(a, tmp, counter);
			return ;
		}
		tmp = tmp->prev;
		size--;
	}
}

void	find_dup(t_stack *a)
{
	t_node	*k;
	t_node	*j;

	k = a->top;
	while (k)
	{
		j = k->prev;
		while (j)
		{
			if (k->value == j->value)
				catch_error("Duplicate");
			j = j->prev;
		}
		k = k->prev;
	}
}

int	calc_index(t_stack *stack, t_node *successor)
{
	t_node	*tmp;
	int		i;

	if (successor->value == stack->top->value)
		return (0);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value == successor-> value)
			break ;
		i++;
		tmp = tmp->prev;
	}
	return (i);
}

int	find_successor(t_stack *go, t_node *base)
{
	t_node	*tmp;
	t_node	*min_go;
	t_node	*max_go;
	t_node	*successor;

	tmp = go->top;
	min_go = go->top;
	max_go = go->top;
	while (tmp)
	{
		if (tmp->value > max_go->value)
			max_go = tmp;
		if (tmp->value < min_go->value)
			min_go = tmp;
		tmp = tmp->prev;
	}
	tmp = go->top;
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > base->value)
		{
			if (successor == NULL)
				successor = tmp;
			else if (successor->value > tmp->value)
				successor = tmp;
		}
		tmp = tmp->prev;
	}
	if (successor == NULL)
		return (calc_index(go, max_go));
	else
		return (calc_index(go, successor));

}


int	calc_price(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		price;
	int		tmp_price;
	int		tmp_v;
	int		tmp_s;

	tmp = a->top;
	price = 2147483647;
	while (tmp)
	{
		tmp_v = find_successor(b, tmp);
		tmp_s = calc_index(a, tmp);
		if (b->size / 2 >= tmp_v)
		{
			if (a->size / 2 >= tmp_s && tmp_v >= tmp_s)
				tmp_price = tmp_v;
			else if (a->size / 2 >= tmp_s && tmp_v < tmp_s)
				tmp_price = tmp_s;
			else
				tmp_price = tmp_v + a->size - tmp_s;
		}
		else
		{
			if (a->size / 2 <= tmp_s && tmp_v >= tmp_s)
				tmp_price = a->size - tmp_s;
			else if (a->size / 2 >= tmp_s && tmp_v < tmp_s)
				tmp_price = b->size - tmp_v;
			else
				tmp_price = tmp_s + b->size - tmp_v;
		}

		if (price > tmp_price)
			price = tmp_price;
		tmp = tmp->prev;
	}
	return (++price);
}

int	main(int c, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		counter;

	init(&a, &b);
	i = 1;
	counter = 0;
	while (argv[i])
	{
		add_to_bottom(create_node(ft_atoi(argv[i])), &a);
		i++;
	}
	if (c == 1)
		catch_error("No input");
	find_dup(&a);
	while (a.size > 3)
	{
		if (b.size < 2)
			pa(&a, &b, &counter);
		else
			calc_price(&a, &b);
	}
	if (b.size)
	{
		while (b.size > 0)
		{
			add_to_back(&a, &b, &counter);
		}
		find_put_smallest(&a, &counter);
		t_node *tmp;
		tmp = a.top;
		while (tmp)
		{
			printf("value: %i\n", tmp->value);
			tmp = tmp->prev;
		}
		printf("count: %i \n", counter);
		return (EXIT_SUCCESS);
	}
	find_put_smallest(&a, &counter);
	t_node *tmp;
	tmp = a.top;
	while (tmp)
	{
		printf("value: %i\n", tmp->value);
		tmp = tmp->prev;
	}
	printf("count: %i \n", counter);
}
