/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:49:27 by emrul             #+#    #+#             */
/*   Updated: 2025/11/11 10:09:55 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_up_from(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor_b(next_to, to));
	while (move_from--)
		rb(from);
	while (move_to--)
		rra(to);
}

static void	move_up_to(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_b(next_to, to));
	while (move_from--)
		rrb(from);
	while (move_to--)
		ra(to);
}

static void	move_up(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_b(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rr(from, to);
		while (move_from--)
			rb(from);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rr(from, to);
		while (move_to--)
			ra(to);
	}
	else
		while (move_from--)
			rr(from, to);
}

static void	move_down(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor_b(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rrr(from, to);
		while (move_from--)
			rrb(from);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rrr(from, to);
		while (move_to--)
			rra(to);
	}
	else
		while (move_from--)
			rrr(from, to);
}

void	move_b(t_node **next_to, t_stack *from, t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_b(next_to, to));
	if ((move_from >= 0 && move_to >= 0))
		move_up(next_to, from, to);
	else if (move_from <= 0 && move_to <= 0)
		move_down(next_to, from, to);
	else
	{
		if (move_from >= 0)
			move_up_from(next_to, from, to);
		else
			move_up_to(next_to, from, to);
	}
}
