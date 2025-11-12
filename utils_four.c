/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:42:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/12 12:46:04 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_ft_atoi(long n, t_stack *a, t_stack *b)
{
	if (n > INT_MAX || n < INT_MIN)
		catch_error("Error", a, b);
}

int	ft_atoi_split(const char *nptr, t_stack *a, t_stack *b, char ***argv_two)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -sign;
	if (!nptr[i])
		catch_error("Error", a, b);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i++] - '0');
		check_ft_atoi(n * sign, a, b);
	}
	if (nptr[i])
	{
		free_words(*argv_two);
		catch_error("Error", a, b);
	}
	return (n * sign);
}
