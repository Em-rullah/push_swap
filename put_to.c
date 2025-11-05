/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:32:32 by emkir             #+#    #+#             */
/*   Updated: 2025/11/05 14:06:41 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_to_b(t_stack *a, t_stack *b, int *counter, t_node *next_on)
{
	while (a->size > 3)
	{
		if (b->size < 2)
			pb(a, b, counter);
		else
		{
			calc_price(a, b, next_on);
			move(next_on, a, b, counter);
			pb(a, b, counter);
		}
	}
}

void	put_to_a(t_stack *a, t_stack *b, int *counter, t_node *next_on)
{
	while (b->size > 0)
	{
		calc_price(b, a, next_on);
		move(next_on, a, b, counter);
		pa(a, b, counter);
	}
}

void	find_min_max(t_node *min_go, t_node *max_go, t_stack *go)
{
	t_node	*tmp;

	tmp = go->top;
	while (tmp)
	{
		if (tmp->value > max_go->value)
			max_go = tmp;
		if (tmp->value < min_go->value)
			min_go = tmp;
		tmp = tmp->prev;
	}
}

int	find_successor(t_node *base, t_stack *go)
{
	t_node	*tmp;
	t_node	*min_go;
	t_node	*max_go;
	t_node	*successor;

	min_go = go->top;
	max_go = go->top;
	find_min_max(min_go, max_go, go);
	tmp = go->top;
	if (base->value < min_go->value || base->value > max_go->value)
		return (calc_index(go, min_go));
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > base->value)
			if (!successor || tmp->value < successor->value)
				successor = tmp;
		tmp = tmp->prev;
	}
	return (calc_index(go, successor));
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