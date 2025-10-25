
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

void	calc_rota(t_stack *a, int *counter)
{
	t_node	*tmp;
	t_node	*min;

	min = a->top;
	tmp = a->top;
	while (tmp)
	{
		if (min->value > tmp->value)
			min = tmp;
		tmp = tmp->prev;
	}
	push_to_top(a, min, counter);
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

void	add_to_back(t_stack *a, t_stack *b, int *counter)
{
	t_node	*tmp;
	t_node	*min_a;
	t_node	*max_a;
	t_node	*successor;
	int		i;

	tmp = a->top;
	min_a = a->top;
	max_a = a->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value > max_a->value)
			max_a = tmp;
		if (tmp->value < min_a->value)
			min_a = tmp;
		tmp = tmp->prev;
	}
	tmp = a->top;
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > b->top->value)
		{
			if (successor == NULL)
				successor = tmp;
			else if (successor->value > tmp->value)
				successor = tmp;
		}
		tmp = tmp->prev;
	}
	if (successor == NULL)
	{
		calc_rota(a, counter);
		pa(a, b, counter);
	}
	else
	{
		push_to_top(a, successor, counter);
		pa(a, b, counter);
	}

}

int	main(int c, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		warp;
	int		counter;

	init(&a, &b);
	i = 1;
	counter = 0;
	while (argv[i])
	{
		add_to_bottom(create_node(ft_atoi(argv[i])), &a);
		i++;
	}
	if (a.top == NULL)
		catch_error("No input");
	find_dup(&a);
	warp = calc_wrap(&a);
	while (warp > 1 && a.size > 3)
	{
		calc_rota(&a, &counter);
		pb(&a, &b, &counter);
		warp = calc_wrap(&a);
	}
	if (b.size)
	{
		while (b.size > 0)
		{
			add_to_back(&a, &b, &counter);
		}
		calc_rota(&a, &counter);
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
	calc_rota(&a, &counter);
	t_node *tmp;
	tmp = a.top;
	while (tmp)
	{
		printf("value: %i\n", tmp->value);
		tmp = tmp->prev;
	}
	printf("count: %i \n", counter);
}
