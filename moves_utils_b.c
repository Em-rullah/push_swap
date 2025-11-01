/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:42:34 by emkir             #+#    #+#             */
/*   Updated: 2025/11/01 18:45:07 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    up_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
{
    if (moves_from < 0)
		moves_from *= -1;
	if (moves_to < 0)
		moves_to *= -1;
    while (moves_to--)
    {
        rr(from, to, counter);
        moves_to--;
    }
    while (moves_from--)
        rb(from, counter);
}
void    down_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
{
    if (moves_from < 0)
		moves_from *= -1;
	if (moves_to < 0)
		moves_to *= -1;
    while (moves_to--)
    {
        rrr(from, to, counter);
        moves_from--;
    }
    while (moves_from--)
        rrb(from, counter);
}
void up_re_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
{
    while (move_from--)
        rb(from, counter);
    while (move_to++)
        rra(to, counter);
}