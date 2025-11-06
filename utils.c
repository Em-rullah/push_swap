/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:08 by emkir             #+#    #+#             */
/*   Updated: 2025/11/06 10:51:13 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	clean_b(t_stack *b)
{
	t_node	*cur;
	t_node	*tmp;

	if (!b)
		return ;
	cur = b->top;
	while (cur)
	{
		tmp = cur->prev;
		free(cur);
		cur = tmp;
	}
	b->size = 0;
}

void	clean_a(t_stack *a)
{
	t_node	*cur;
	t_node	*tmp;

	if (!a)
		return ;
	cur = a->top;
	while (cur)
	{
		tmp = cur->prev;
		free(cur);
		cur = tmp;
	}
	a->size = 0;
}

void	catch_error(char *msg, t_stack *a, t_stack *b)
{
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	clean_a(a);
	clean_b(b);
	exit(EXIT_FAILURE);
}

static void	check_ft_atoi(long n, t_stack *a, t_stack *b)
{
	if (n > 2147483647 || n < -2147483648L)
		catch_error("OVERFLOW", a, b);
}

int	ft_atoi(const char *nptr, t_stack *a, t_stack *b)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	if (!nptr[i])
		catch_error("Invalid input", a, b);
	while ('0' <= nptr[i] && nptr[i] <= '9')
		n = 10 * n + (nptr[i++] - '0');
	if (nptr[i])
		catch_error("Invalid input", a, b);
	check_ft_atoi(n * sign, a, b);
	return (n * sign);
}