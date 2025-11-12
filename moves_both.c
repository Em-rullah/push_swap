/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:10:29 by emkir             #+#    #+#             */
/*   Updated: 2025/11/12 12:41:57 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_down(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->bottom;
	stack->bottom = tmp->next;
	stack->bottom->prev = NULL;
	stack->top->next = tmp;
	tmp->prev = stack->top;
	stack->top = tmp;
	tmp->next = NULL;
}

static void	rotate_up(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	stack->bottom->prev = tmp;
	tmp->next = stack->bottom;
	stack->bottom = tmp;
	tmp->prev = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
}
