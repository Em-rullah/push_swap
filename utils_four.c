/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:42:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/15 16:01:52 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	catch_error_split(char *msg, t_stack *a,
						t_stack *b, char ***argv_two)
{
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	clean_a(a);
	clean_b(b);
	free_words(*argv_two);
	exit(EXIT_FAILURE);
}

static void	check_ft_atoi(long n, t_stack *a, t_stack *b, char ***argv_two)
{
	if (n > INT_MAX || n < INT_MIN)
		catch_error_split("Error", a, b, argv_two);
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
		catch_error_split("Error", a, b, argv_two);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i++] - '0');
		check_ft_atoi(n * sign, a, b, argv_two);
	}
	if (nptr[i])
	{
		free_words(*argv_two);
		catch_error("Error", a, b);
	}
	return (n * sign);
}
