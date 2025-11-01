/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:16:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/01 18:44:45 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void    up_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
{
    if (moves_from < 0)
		moves_from *= -1;
	if (moves_to < 0)
		moves_to *= -1;
    while (moves_to--)
    {
        rr(from, to, counter);
        tmp_from--;
    }
    while (moves_from--)
        ra(from, counter);
}
void    down_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
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
        rra(from, counter);
}
void up_re_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter)
{
    while (move_from--)
        ra(from, counter);
    while (move_to++)
        rrb(to, counter);
}