/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:50:54 by emrul             #+#    #+#             */
/*   Updated: 2025/11/06 10:51:18 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


t_node	*create_node(int value, t_stack *a, t_stack *b)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		catch_error("Error while initializing", a, b);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void	add_to_bottom(t_node *node, t_stack *stack)
{

	if (stack->size != 0)
	{
		node->next = stack->bottom;
		stack->bottom->prev = node;
		stack->bottom = node;
	}
	else
	{
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

void	init(t_stack *a, t_stack *b, int *counter)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
	*counter = 0;
}
