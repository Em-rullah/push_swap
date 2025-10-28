
#include "main.h"

void	catch_error(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *nptr)
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
	{
		if (nptr[i++] == '-')
			sign = -sign;
	}
	if (!nptr[i])
		catch_error("Invalid input");
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i++] - '0');
	}
	if (nptr[i])
		catch_error("Invalid input");
	return (n * sign);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		catch_error("Error while initializing");
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void	add_to_bottom(t_node *node, t_stack *stack)
{

	if (stack->size != 0)
	{
		node->next = stack->bottom;
		stack->bottom->prev = node;
		stack->bottom = node;
	}
	else
	{
		stack->top = node;
		stack->bottom = node;
	}
	stack->size++;
}

int	calc_wrap(t_stack *a)
{
	t_node	*tmp;
	int		result;

	result = 0;
	tmp = a->top;
	while (tmp->prev)
	{
		if (tmp->value > tmp->prev->value)
			result++;
		tmp = tmp->prev;
	}
	if (a->bottom->value > a->top->value)
		result++;
	return (result);
}
