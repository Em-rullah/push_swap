
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

void	add_to_back(t_stack *a, t_stack *b, int *counter)
{
	t_node	*tmp;
	t_node	*min_a;
	t_node	*max_a;
	t_node	*successor;

	tmp = a->top;
	min_a = a->top;
	max_a = a->top;
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
		find_put_smallest(a, counter);
		pa(a, b, counter);
	}
	else
	{
		push_to_top(a, successor, counter);
		pa(a, b, counter);
	}

}

void	sort_arr(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
void	append_index(int *arr, t_stack *a)
{
	int		i;
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (arr[i] == tmp->value)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->prev;
	}
	free(arr);
}

void create_index(t_stack *a)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = (int *)malloc(sizeof(int) * a->size);
	if (!arr)
		catch_error("Cannot init.");
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->prev;
	}
	sort_arr(arr, a->size);
	append_index(arr, a);
}

int	calc_chunk(t_stack *a)
{
	if (a->size <= 20)
		return (2);
	else if (a->size <= 200 && a->size >= 21)
		return (6);
	else
		return (10);
}

void	push_to_b(t_stack *a, t_stack *b, int chunk)
{
c
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
	create_index(&a);
	push_to_b(&a, &b, calc_chunk(&a));
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
