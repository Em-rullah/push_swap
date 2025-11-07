/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:49:27 by emrul             #+#    #+#             */
/*   Updated: 2025/11/07 08:57:29 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	move_up_a_b(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = -1 * calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor(next_to, to));
	while (move_from--)
		rrb(from, counter);
	while (move_to--)
		ra(to, counter);
}

static void	move_up_b_b(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = -1 * calc_move(to, find_successor(next_to, to));
	while (move_from--)
		rb(from, counter);
	while (move_to--)
		rra(to, counter);
}

static void	move_up_both_b(t_node **next_to, t_stack *from,
	t_stack *to, int *counter)
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
			rb(from, counter);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rr(from, to, counter);
		while (move_to--)
			ra(to, counter);
	}
	else
		while (move_from--)
			rr(from, to, counter);
}

static void	move_down_both_b(t_node **next_to, t_stack *from,
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
			rrb(from, counter);
	}
	else if (move_from < move_to)
	{
		move_to -= move_from;
		while (move_from--)
			rrr(from, to, counter);
		while (move_to--)
			rra(to, counter);
	}
	else
		while (move_from--)
			rrr(from, to, counter);
}

void	move_b(t_node **next_to, t_stack *from, t_stack *to, int *counter)
{
	int	move_from;
	int	move_to;

	move_from = calc_move(from, calc_index(from, next_to));
	move_to = calc_move(to, find_successor(next_to, to));
	if ((move_from >= 0 && move_to >= 0))
		move_up_both_b(next_to, from, to, counter);
	else if (move_from <= 0 && move_to <= 0)
		move_down_both_b(next_to, from, to, counter);
	else
	{
		if (move_from >= 0)
			move_up_b_b(next_to, from, to, counter);
		else
			move_up_a_b(next_to, from, to, counter);
	}
}
