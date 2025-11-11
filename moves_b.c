/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:13 by emkir             #+#    #+#             */
/*   Updated: 2025/11/11 09:54:40 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	tmp->prev = stack->top->prev;
	tmp->next = stack->top;
	if (stack->top->prev != NULL)
		stack->top->prev->next = tmp;
	else
		stack->bottom = tmp;
	stack->top->prev = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp_a;

	tmp_a = a->top;
	a->top = tmp_a->prev;
	a->top->next = NULL;
	if (!a->top->prev)
		a->bottom = a->top;
	if (b->top)
	{
		tmp_a->prev = b->top;
		b->top->next = tmp_a;
	}
	else
	{
		tmp_a->prev = NULL;
		b->bottom = tmp_a;
	}
	b->top = tmp_a;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}

void	rb(t_stack *stack)
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
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
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
	write(1, "rrb\n", 4);
}
