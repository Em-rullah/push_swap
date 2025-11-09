/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:32:32 by emkir             #+#    #+#             */
/*   Updated: 2025/11/08 13:28:50 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_to_b(t_stack *a, t_stack *b, t_node **next_on)
{
	while (a->size > 3)
	{
		if (b->size < 2)
			pb(a, b);
		else
		{
			calc_price(a, b, next_on);
			move_a(next_on, a, b);
			pb(a, b);
		}
	}
}

void	put_to_a(t_stack *b, t_stack *a, t_node **next_on)
{
	while (b->size > 0)
	{
		calc_price(b, a, next_on);
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
