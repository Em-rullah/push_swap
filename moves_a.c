
#include "main.h"

void	sa(t_stack *stack, int *counter)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	tmp->prev = stack->top->prev;
	tmp->next = stack->top;
	if (stack->top->prev != NULL) //  ÖNCEKİ 2.NİN ALTINDAKİ SON ELEMAN MI KONTROLÜ
		stack->top->prev->next = tmp;
	else
		stack->bottom = tmp;
	stack->top->prev = tmp;
	printf("sa\n");
	(*counter)++;
}

void	pa(t_stack *a, t_stack *b, int *counter)
{
	t_node	*tmp_b;

	if (!b->top)
		return ;
	tmp_b = b->top;
	if (tmp_b->prev)
	{
		b->top = tmp_b->prev;
		b->top->next = NULL;
		if (!b->top->prev)
			b->bottom = b->top;
	}
	else
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	tmp_b->prev = a->top;
	a->top->next = tmp_b;
	a->top = tmp_b;
	a->size++;
	b->size--;
	printf("pa\n");
	(*counter)++;
}

void	ra(t_stack *stack, int *counter)
{
	t_node	*tmp;
	if (stack->size < 2) // BOŞ + TEK KONTROLÜ
		return ;
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;

	stack->bottom->prev = tmp;
	tmp->next = stack->bottom;
	stack->bottom = tmp;
	tmp->prev = NULL;
	printf("ra\n");
	(*counter)++;
}

void	rra(t_stack *stack, int *counter)
{
	t_node	*tmp;

	if (stack->size < 2) // BOŞ + TEK KONTROLÜ
		return ;
	tmp = stack->bottom;
	stack->bottom = tmp->next;
	stack->bottom->prev = NULL;

	stack->top->next = tmp;
	tmp->prev = stack->top;
	stack->top = tmp;
	tmp->next = NULL;
	printf("rra\n");
	(*counter)++;
}
