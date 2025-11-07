/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:50:19 by emkir             #+#    #+#             */
/*   Updated: 2025/11/07 11:30:17 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*new_s;

	i = 0;
	size = ft_strlen(s);
	new_s = malloc (sizeof(char) * (size + 1));
	if (!new_s)
		return (0);
	while (size)
	{
		new_s[i] = *s;
		s++;
		i++;
		size--;
	}
	new_s[i] = '\0';
	return (new_s);
}

void	populate_a(char *argv[], t_stack *a, t_stack *b)
{
	int		j;
	int		i;
	char	**argv_two;

	i = 1;
	while (argv[i])
	{
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
		i++;
	}
}

int	main(int c, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		counter;
	t_node	*next_on;

	init(&a, &b, &counter);
	if (c == 1)
		catch_error("Error", &a, &b);
	populate_a(argv, &a, &b);
	find_dup(&a, &b);
	next_on = a.top;
	put_to_b(&a, &b, &counter, &next_on);
	sort_a(&a, &counter);
	next_on = b.top;
	put_to_a(&b, &a, &counter, &next_on);
	place_smallest(&a, &counter);
	clean_a(&a);
	clean_b(&b);
}
