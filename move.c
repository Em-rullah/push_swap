/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:55:36 by emkir             #+#    #+#             */
/*   Updated: 2025/11/07 08:43:18 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	move_up(t_node **next_to, t_stack *from, t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rr(from, to, counter);
		while (move_from--)
			ra(from, counter);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rr(from, to, counter);
		while (move_to--)
			rb(to, counter);
	}
	else
		while (move_from--)
			rr(from, to, counter);
}

static void	move_up_a(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor(next_to, to));
	while (move_from--)
		ra(from, counter);
	while (move_to--)
		rrb(to, counter);
}

static void	move_up_b(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor(next_to, to));
	while (move_from--)
		rra(from, counter);
	while (move_to--)
		rb(to, counter);
}

static void	move_down(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor(next_to, to));
	if (move_from > move_to)
	{
		move_from -= move_to;
		while (move_to--)
			rrr(from, to, counter);
		while (move_from--)
			rra(from, counter);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rrr(from, to, counter);
		while (move_to--)
			rrb(to, counter);
	}
	else
		while (move_from--)
			rrr(from, to, counter);
}

void	move(t_node **next_to, t_stack *from, t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor(next_to, to));
	if ((move_from >= 0 && move_to >= 0))
		move_up(next_to, from, to, counter);
	else if (move_from <= 0 && move_to <= 0)
		move_down(next_to, from, to, counter);
	else
	{
		if (move_from >= 0)
			move_up_a(next_to, from, to, counter);
		else
			move_up_b(next_to, from, to, counter);
	}
}
