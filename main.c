
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

int	calc_index(t_stack *stack, t_node *node)
{
	t_node	*tmp;
	int		i;

	if (node->value == stack->top->value)
		return (0);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value == node-> value)
			break ;
		i++;
		tmp = tmp->prev;
	}
	return (i);
}


// BURASI HATALI BURAYA BAK BURADAN PATLIYORSUN
int	find_successor(t_node *base, t_stack *go)
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
	if (base->value < min_go->value || base->value > max_go->value)
	{
		return (calc_index(go, min_go));
	}
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > base->value)
		{
			if (!successor || tmp->value < successor->value)
				successor = tmp;
		}
		tmp = tmp->prev;
	}
	return (calc_index(go, successor));
}

void	move(int i_from, int i_to, t_stack *from, t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;
	int	tmp_from;
	int	tmp_to;

	if (from->size / 2 >= i_from)
		move_from = i_from;
	else
		move_from = i_from - from->size;
	if (to->size / 2 >= i_to)
		move_to = i_to;
	else
		move_to = i_to - to->size;

	if (move_from == 0)
	{
		if (move_to > 0)
			while (move_to--)
				rb(to, counter);
		else
			while (move_to++)
				rrb(to, counter);
		return ;
	}
	if (move_to == 0)
	{
		if (move_from > 0)
			while (move_from--)
				ra(from, counter);
		else
			while (move_from++)
				rra(from, counter);
		return ;
	}
	if ((move_from > 0 && move_to > 0) || (move_from < 0 && move_to < 0))
	{
		if (move_from < 0)
			tmp_from = move_from * -1;
		else
			tmp_from = move_from;
		if (move_to < 0)
			tmp_to = move_to * -1;
		else
			tmp_to = move_to;
		if (move_from > 0)
		{
			if (tmp_from > tmp_to)
			{
				while (tmp_to--)
				{
					rr(from, to, counter);
					tmp_from--;
				}
				while (tmp_from--)
					ra(from, counter);

			}
			else if (tmp_from < tmp_to)
			{
				while (tmp_from--)
				{
					rr(from, to, counter);
					tmp_to--;
				}
				while (tmp_to--)
					rb(to, counter);
			}
			else
			{
				while (tmp_to--)
					rr(from, to, counter);
			}
		}
		else
		{
			if (tmp_from > tmp_to)
			{
				while (tmp_to--)
				{
					rrr(from, to, counter);
					tmp_from--;
				}
				while (tmp_from--)
					rra(from, counter);
			}
			else if (tmp_from < tmp_to)
			{
				while (tmp_from--)
				{
					rrr(from, to, counter);
					tmp_to--;
				}
				while (tmp_to--)
					rrb(to, counter);
			}
			else
			{
				while (tmp_to--)
					rrr(from, to, counter);
			}
		}
	}
	else if ((move_from > 0 && move_to < 0) || (move_from < 0 && move_to > 0))
	{
		if (move_from > 0)
		{
			while (move_from--)
				ra(from, counter);
			while (move_to++)
				rrb(to, counter);
		}
		else
		{
			while (move_from++)
				rra(from, counter);
			while (move_to--)
				rb(to, counter);
		}
	}
}



void	calc_price(t_stack *from, t_stack *to, int *counter)
{
	t_node	*tmp;
	int		price;
	int		tmp_price;
	int		tmp_i_to;
	int		tmp_i_from;
	int		i_to;
	int		i_from;
	int		move_from;
	int		move_to;

	tmp = from->top;
	price = 2147483647;
	move_to = 0;
	move_from = 0;
	while (tmp)
	{
		tmp_i_to = find_successor(tmp, to);
		tmp_i_from = calc_index(from, tmp);
		if (to->size / 2 >= tmp_i_to)
			move_to = tmp_i_to;
		else
			move_to = tmp_i_to - to->size;
		if (from->size / 2 >= tmp_i_from)
			move_from = tmp_i_from;
		else
			move_from = tmp_i_from - from->size;
		if ((move_to > 0 && move_from > 0) || (move_to < 0 && move_from < 0))
		{
			if (move_from < 0)
				move_from *= -1;
			if (move_to < 0)
				move_to *= -1;
			if (move_to > move_from)
				tmp_price = move_to;
			else
				tmp_price = move_from;
		}
		else
		{
			if (move_from < 0)
				move_from *= -1;
			if (move_to < 0)
				move_to *= -1;
			tmp_price = move_from + move_to;
		}
		if (price > tmp_price)
		{
			price = tmp_price;
			i_to = tmp_i_to;
			i_from = tmp_i_from;
		}
		tmp = tmp->prev;
	}
	move(i_from, i_to, from, to, counter);
}

void	place_smallest(t_stack *a ,int *counter)
{
	t_node	*smallest;
	t_node	*tmp;
	int		i;

	smallest = a->top;
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value < smallest->value)
			smallest = tmp;
		tmp = tmp->prev;
	}
	i = calc_index(a, smallest);
	if (a->size / 2 > i)
		while (i--)
			ra(a, counter);
	else
		while (a->size - i++)
			rra(a, counter);
}

void	sort_a(t_stack *a, int *counter)
{
	int	x;
	int	y;
	int	z;

	x = a->top->value;
	y = a->top->prev->value;
	z = a->bottom->value;

	if (x > y && y < z && x < z)
		sa(a, counter);
	else if (x > y && y > z)
	{
		sa(a, counter);
		rra(a, counter);
	}
	else if (x > y && y < z && x > z)
		ra(a, counter);
	else if (x < y && y > z && x < z)
	{
		sa(a, counter);
		ra(a, counter);
	}
	else if (x < y && y > z && x > z)
		rra(a, counter);
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
			pb(&a, &b, &counter);
		else
		{
			calc_price(&a, &b, &counter);
			pb(&a, &b, &counter);
		}
	}
	sort_a(&a, &counter);
	while (b.size > 0)
	{
		calc_price(&b, &a, &counter);
		pa(&a, &b, &counter);
	}
	place_smallest(&a, &counter);
	t_node *tempo_a = a.top;
	printf("A STACK count:%i for size:%i\n", counter, a.size);
	while (tempo_a)
	{
		printf("%i\n", tempo_a->value);
		tempo_a = tempo_a->prev;
	}
}
