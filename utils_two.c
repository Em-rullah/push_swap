/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:16:51 by emrul             #+#    #+#             */
/*   Updated: 2025/11/11 09:54:40 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_move(t_stack *stack, int i)
{
	if (stack->size / 2 >= i)
		return (i);
	else
		return (i - stack->size);
}

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

void	place_smallest(t_stack *a)
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
			ra(a);
	else
		while (a->size - i++)
			rra(a);
}

void	populate_a(char *argv[], t_stack *a, t_stack *b, int i)
{
	int		j;
	char	**argv_two;

	if (ft_strchr(argv[i]))
	{
		j = 0;
		argv_two = ft_split(argv[i]);
		if (!argv_two)
			catch_error("Error", a, b);
		if (!argv_two[j])
		{
			free_words(argv_two);
			catch_error("Error", a, b);
		}
		while (argv_two[j])
			add_to_bottom(create_node(ft_atoi(argv_two[j++], a,
						b), a, b), a);
		free_words(argv_two);
	}
	else
		add_to_bottom(create_node(ft_atoi(argv[i], a, b), a, b), a);
}
