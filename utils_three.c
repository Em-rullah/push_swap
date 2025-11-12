/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:50:54 by emrul             #+#    #+#             */
/*   Updated: 2025/11/12 12:16:09 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value, t_stack *a, t_stack *b)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		catch_error("Error", a, b);
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

void	init(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

int	find_successor_b(t_node **base, t_stack *go)
{
	t_node	*tmp;
	t_node	*min_go;
	t_node	*max_go;
	t_node	*successor;

	min_go = go->top;
	max_go = go->top;
	find_min_max(&min_go, &max_go, go);
	tmp = go->top;
	if ((*base)->value < min_go->value || (*base)->value > max_go->value)
		return (calc_index(go, &min_go));
	successor = NULL;
	while (tmp)
	{
		if (tmp->value > (*base)->value)
			if (!successor || tmp->value < successor->value)
				successor = tmp;
		tmp = tmp->prev;
	}
	return (calc_index(go, &successor));
}

void	sort_a(t_stack *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->prev->value;
	bottom = a->bottom->value;
	if (top > middle && middle < bottom && top < bottom)
		sa(a);
	else if (top > middle && middle > bottom)
	{
		sa(a);
		rra(a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
}
