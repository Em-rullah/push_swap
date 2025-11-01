/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/01 18:51:31 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

int		ft_atoi(const char *nptr);
void	add_to_bottom(t_node *node, t_stack *stack);
t_node	*create_node(int value);
void	catch_error(char *msg);
int		calc_wrap(t_stack *a);

void	sa(t_stack *stack, int *counter);
void	pa(t_stack *a, t_stack *b, int *counter);
void	ra(t_stack *stack, int *counter);
void	rra(t_stack *stack, int *counter);

void	sb(t_stack *stack, int *counter);
void	pb(t_stack *a, t_stack *b, int *counter);
void	rb(t_stack *stack, int *counter);
void	rrb(t_stack *stack, int *counter);
void	rr(t_stack *a, t_stack *b, int *counter);
void	rrr(t_stack *a, t_stack *b, int *counter);
void	init(t_stack *a, t_stack *b);

void up_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);
void down_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);
void up_re_a(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);
void up_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);
void down_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);
void down_re_b(int moves_from, int moves_to, t_stack *from, t_stack *to, int *counter);

#endif