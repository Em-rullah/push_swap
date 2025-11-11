/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:55:36 by emkir             #+#    #+#             */
/*   Updated: 2025/11/11 10:04:47 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_up_from(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor_a(next_to, to));
	while (move_from--)
		ra(from);
	while (move_to--)
		rrb(to);
}

static void	move_up_to(t_node **next_to, t_stack *from,
	t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_a(next_to, to));
	while (move_from--)
		rra(from);
	while (move_to--)
		rb(to);
}

static void	move_up(t_node **next_to, t_stack *from, t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_a(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rr(from, to);
		while (move_from--)
			ra(from);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rr(from, to);
		while (move_to--)
			rb(to);
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
	move_to = -1 * calc_move(to, find_successor_a(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rrr(from, to);
		while (move_from--)
			rra(from);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rrr(from, to);
		while (move_to--)
			rrb(to);
	}
	else
		while (move_from--)
			rrr(from, to);
}

void	move_a(t_node **next_to, t_stack *from, t_stack *to)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor_a(next_to, to));
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
