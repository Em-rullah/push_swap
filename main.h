
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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