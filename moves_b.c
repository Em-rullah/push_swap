/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:13 by emkir             #+#    #+#             */
/*   Updated: 2025/11/01 16:23:36 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sb(t_stack *stack, int *counter)
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
	printf("sb\n");
	(*counter)++;
}

void	pb(t_stack *a, t_stack *b, int *counter)
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
	printf("pb\n");
	(*counter)++;
}

void	rb(t_stack *stack, int *counter)
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
	printf("rb\n");
	(*counter)++;
}

void	rrb(t_stack *stack, int *counter)
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
	printf("rrb\n");
	(*counter)++;
}
