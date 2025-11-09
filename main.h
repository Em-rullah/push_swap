/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkir <emkir@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:23:06 by emkir             #+#    #+#             */
/*   Updated: 2025/11/09 10:29:36 by emkir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX  2147483647
# define INT_MIN  -2147483648

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

void	calc_price(t_stack *from, t_stack *to, t_node **next_on);

int		is_space(char c);
char	*ft_strchr(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	free_words(char **word_arr);

void	move_a(t_node **next_to, t_stack *from, t_stack *to);

void	move_b(t_node **next_to, t_stack *from, t_stack *to);

void	sa(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *stack);
void	rra(t_stack *stack);

void	sb(t_stack *stack);
void	pb(t_stack *a, t_stack *b);
void	rb(t_stack *stack);
void	rrb(t_stack *stack);

void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	put_to_a(t_stack *b, t_stack *a, t_node **next_on);
void	put_to_b(t_stack *a, t_stack *b, t_node **next_on);
void	find_min_max(t_node **min_go, t_node **max_go, t_stack *go);

char	**ft_split(char const *s);

void	init(t_stack *a, t_stack *b);
int		find_successor(t_node **base, t_stack *go);
void	sort_a(t_stack *a);
void	add_to_bottom(t_node *node, t_stack *stack);
t_node	*create_node(int value, t_stack *a, t_stack *b);

int		calc_move(t_stack *stack, int i);
int		calc_index(t_stack *stack, t_node **node);
void	find_dup(t_stack *a, t_stack *b);
void	place_smallest(t_stack *a);
void	populate_a(char *argv[], t_stack *a, t_stack *b, int i);

void	clean_a(t_stack *a);
void	clean_b(t_stack *b);
void	catch_error(char *msg, t_stack *a, t_stack *b);
int		ft_atoi(const char *nptr, t_stack *a, t_stack *b);

#endif