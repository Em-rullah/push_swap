/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrul <emrul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/06 10:42:46 by emrul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

int		ft_atoi(const char *nptr, t_stack *a, t_stack *b);
void	add_to_bottom(t_node *node, t_stack *stack);
t_node	*create_node(int value, t_stack *a, t_stack *b);
void	catch_error(char *msg, t_stack *a, t_stack *b);
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
void	init(t_stack *a, t_stack *b, int *counter);
void	put_to_a(t_stack *a, t_stack *b, int *counter, t_node **next_on);
void	put_to_b(t_stack *a, t_stack *b, int *counter, t_node **next_on);
int		find_successor(t_node **base, t_stack *go);
void	calc_price(t_stack *from, t_stack *to, t_node **next_on);
void	sort_a(t_stack *a, int *counter);
void	move(t_node **next_to, t_stack *from, t_stack *to, int *counter);
int		calc_move(t_stack *stack, int i);
int		calc_index(t_stack *stack, t_node **node);
void	move_b(t_node **next_to, t_stack *from, t_stack *to, int *counter);
void	clean_a(t_stack *a);
void	clean_b(t_stack *b);
void	find_dup(t_stack *a, t_stack *b);
void	place_smallest(t_stack *a, int *counter);
#endif