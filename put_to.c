/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:32:32 by emkir             #+#    #+#             */
/*   Updated: 2025/11/11 10:09:02 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_to_b(t_stack *a, t_stack *b, t_node **next_on)
{
	while (a->size > 3)
	{
		if (b->size < 2)
			pb(a, b);
		else
		{
			calc_price_a(a, b, next_on);
			move_a(next_on, a, b);
			pb(a, b);
		}
	}
}

void	put_to_a(t_stack *b, t_stack *a, t_node **next_on)
{
	while (b->size > 0)
	{
		calc_price_b(b, a, next_on);
		move_b(next_on, b, a);
		pa(a, b);
	}
}

void	find_min_max(t_node **min_go, t_node **max_go, t_stack *go)
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

int	find_successor_a(t_node **base, t_stack *go)
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
		return (calc_index(go, &max_go));
	successor = NULL;
	while (tmp)
	{
		if (tmp->value < (*base)->value)
			if (!successor || tmp->value > successor->value)
				successor = tmp;
		tmp = tmp->prev;
	}
	return (calc_index(go, &successor));
}
