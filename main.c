/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:50:19 by emkir             #+#    #+#             */
/*   Updated: 2025/11/06 10:56:46 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

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
		catch_error("No input", &a, &b);
	while (argv[i])
		add_to_bottom(create_node(ft_atoi(argv[i++], &a, &b), &a, &b), &a);
	find_dup(&a, &b);
	next_on = a.top;
	put_to_b(&a, &b, &counter, &next_on);
	sort_a(&a, &counter);
	put_to_a(&a, &b, &counter, &next_on);
	place_smallest(&a, &counter);
	t_node *t = a.top;
	while (t)
	{
		printf("%i\n", t->value);
		t = t->prev;
	}
	printf("counter %i\n", counter);
	clean_a(&a);
	clean_b(&b);
}
