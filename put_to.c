/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:32:32 by emkir             #+#    #+#             */
/*   Updated: 2025/11/06 15:33:42 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_to_b(t_stack *a, t_stack *b, int *counter, t_node **next_on)
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

void	put_to_a(t_stack *b, t_stack *a, int *counter, t_node **next_on)
{
	while (b->size > 0)
	{
		calc_price(b, a, next_on);
		move_b(next_on, b, a, counter);
		pa(a, b, counter);
	}
}

static void	find_min_max(t_node **min_go, t_node **max_go, t_stack *go)
{
	t_node	*tmp;

	tmp = go->top;
	while (tmp)
	{
		if (tmp->value > (*max_go)->value)
			*max_go = tmp;
		if (tmp->value < (*min_go)->value)
			*min_go = tmp;
		tmp = tmp->prev;
	}
}

int	find_successor(t_node **base, t_stack *go)
{
	t_node	*tmp;
	t_node	*min_go;
	t_node	*max_go;
	t_node	*successor;

	min_go = go->top;
	max_go = go->top;
	find_min_max(&min_go, &max_go, go);
	tmp = go->top;
	if ((*base)->value < min_go->value || (*base)->value > max_go->value)
		return (calc_index(go, &min_go));
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > (*base)->value)
			if (!successor || tmp->value < successor->value)
				successor = tmp;
		tmp = tmp->prev;
	}
	return (calc_index(go, &successor));
}

void	sort_a(t_stack *a, int *counter)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->prev->value;
	bottom = a->bottom->value;

	if (top > middle && middle < bottom && top < bottom)
		sa(a, counter);
	else if (top > middle && middle > bottom)
	{
		sa(a, counter);
		rra(a, counter);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a, counter);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a, counter);
		ra(a, counter);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a, counter);
}
