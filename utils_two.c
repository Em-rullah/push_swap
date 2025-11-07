/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:16:51 by emrul             #+#    #+#             */
/*   Updated: 2025/11/07 09:02:46 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	find_dup(t_stack *a, t_stack *b)
{
	t_node	*k;
	t_node	*j;

	k = a->top;
	while (k)
	{
		j = k->prev;
		while (j)
		{
			if (k->value == j->value)
				catch_error("Error", a, b);
			j = j->prev;
		}
		k = k->prev;
	}
}

int	calc_index(t_stack *stack, t_node **node)
{
	t_node	*tmp;
	int		i;

	if ((*node)->value == stack->top->value)
		return (0);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value == (*node)->value)
			break ;
		i++;
		tmp = tmp->prev;
	}
	return (i);
}

void	place_smallest(t_stack *a, int *counter)
{
	t_node	*smallest;
	t_node	*tmp;
	int		i;

	smallest = a->top;
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value < smallest->value)
			smallest = tmp;
		tmp = tmp->prev;
	}
	i = calc_index(a, &smallest);
	if (a->size / 2 > i)
		while (i--)
			ra(a, counter);
	else
		while (a->size - i++)
			rra(a, counter);
}
