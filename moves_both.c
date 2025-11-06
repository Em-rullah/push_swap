/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:10:29 by emkir             #+#    #+#             */
/*   Updated: 2025/11/06 13:24:39 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	rr(t_stack *a, t_stack *b, int *counter)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
	(*counter)++;
}


void	rrr(t_stack *a, t_stack *b, int *counter)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
	(*counter)++;
}

int	calc_move(t_stack *stack, int i)
{
	if (stack->size / 2 >= i)
		return (i);
	else
		return (i - stack->size);
}
