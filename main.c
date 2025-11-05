/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:50:19 by emkir             #+#    #+#             */
/*   Updated: 2025/11/05 14:07:33 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

void	find_dup(t_stack *a)
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
				catch_error("Duplicate");
			j = j->prev;
		}
		k = k->prev;
	}
}

int	calc_index(t_stack *stack, t_node *node)
{
	t_node	*tmp;
	int		i;

	if (node->value == stack->top->value)
		return (0);
	tmp = stack->top;
	i = 0;
	while (tmp)
	{
		if (tmp->value == node-> value)
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
	i = calc_index(a, smallest);
	if (a->size / 2 > i)
		while (i--)
			ra(a, counter);
	else
		while (a->size - i++)
			rra(a, counter);
}

int	main(int c, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		counter;
	t_node	*next_on;

	init(&a, &b, &counter);
	i = 1;
	if (c == 1)
	catch_error("No input");
	while (argv[i])
	add_to_bottom(create_node(ft_atoi(argv[i++])), &a);
	next_on = a.top;
	put_to_b(&a, &b, &counter, next_on);
	put_to_a(&a, &b, &counter, next_on);
	find_dup(&a);
	sort_a(&a, &counter);
	place_smallest(&a, &counter);
}
