/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:50:19 by emkir             #+#    #+#             */
/*   Updated: 2025/11/12 12:14:06 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_words(char **word_arr)
{
	int	i;

	i = 0;
	while (word_arr[i])
	{
		free(word_arr[i]);
		i++;
	}
	free(word_arr);
}

static void	check_sorted(t_stack *a)
{
	t_node	*tmp;
	int		checker;

	tmp = a->top;
	checker = 0;
	while (tmp != a->bottom)
	{
		if (tmp->value > tmp->prev->value)
			checker = 1;
		tmp = tmp->prev;
	}
	if (checker == 0)
	{
		clean_a(a);
		exit(EXIT_SUCCESS);
	}	
	else
		return ;
}

int	main(int c, char *argv[])
{
	int		i;
	t_stack	a;
	t_stack	b;
	t_node	*next_on;

	i = 1;
	init(&a, &b);
	if (c == 1)
		return (1);
	while (argv[i])
		populate_a(argv, &a, &b, i++);
	find_dup(&a, &b);
	check_sorted(&a);
	next_on = a.top;
	put_to_b(&a, &b, &next_on);
	sort_a(&a);
	next_on = b.top;
	put_to_a(&b, &a, &next_on);
	place_smallest(&a);
	clean_a(&a);
	clean_b(&b);
}
