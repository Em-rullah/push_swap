/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_price_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:46:05 by emkir             #+#    #+#             */
/*   Updated: 2025/11/11 10:09:29 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_same_slice(int move_to, int move_from)
{
	if (move_to >= 0 && move_from >= 0)
	{
		if (move_to > move_from)
			return (move_to);
		else
			return (move_from);
	}
	else
	{
		if (-move_to > -move_from)
			return (-move_to);
		else
			return (-move_from);
	}
}

static int	calc_different_slice(int move_to, int move_from)
{
	if (move_to < 0)
		move_to *= -1;
	if (move_from < 0)
		move_from *= -1;
	return (move_to + move_from);
}

static void	calc_moves_to(t_stack *to, int *move_to, t_node **tmp)
{
	*move_to = calc_move(to, find_successor_b(tmp, to));
}

static void	calc_moves_from(t_stack *from, int *move_from, t_node **tmp)
{
	*move_from = calc_move(from, calc_index(from, tmp));
}

void	calc_price_b(t_stack *from, t_stack *to, t_node **next_on)
{
	t_node	*tmp;
	int		price;
	int		tmp_price;
	int		move_to;
	int		move_from;

	tmp = from->top;
	price = 2147483647;
	while (tmp)
	{
		calc_moves_to(to, &move_to, &tmp);
		calc_moves_from(from, &move_from, &tmp);
		if ((move_to >= 0 && move_from >= 0)
			|| (move_to < 0 && move_from < 0))
			tmp_price = calc_same_slice(move_to, move_from);
		else
			tmp_price = calc_different_slice(move_to, move_from);
		if (price > tmp_price)
		{
			price = tmp_price;
			*next_on = tmp;
		}
		tmp = tmp->prev;
	}
}
