#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	swap(t_list *gen, char *op, int p)
{
	int	swap;

	if (gen->next != NULL)
	{
		swap = gen->data;
		gen->data = gen->next->data;
		gen->next->data = swap;
		if (p == 1)
		{
			write(1, op, 2);
			write(1, "\n", 1);
		}
	}
}

void	push(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	front_add(b, temp->data);
	temp = temp->next;
	*a = temp;
}

void	rotate(t_list **a)
{
	t_list	*temp;
	int		number;

	temp = *a;
	number = temp->data;
	temp = temp->next;
	*a = temp;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = malloc(sizeof(t_list));
	temp->next->data = number;
}

void	r_rotate(t_list **a)
{
	t_list	*temp;
	int		number;

	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	number = temp->data;
	front_add(a, number);
	temp = *a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
}

void	swap_op(t_general *gen, char *op, int print)
{
	if (ft_strcmp(op, "sa") == 0)
		swap(gen->a, op, print);
	else if (ft_strcmp(op, "sb") == 0)
		swap(gen->b, op, print); 
	else if (ft_strcmp(op, "ss") == 0)
	{
		swap(gen->a, op, print);
		swap(gen->b, op, print);
	}
	else if (ft_strcmp(op, "pb") == 0)
		push(&gen->a, &gen->b);
	else if (ft_strcmp(op, "pa") == 0)
		push(&gen->b, &gen->a);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(&gen->a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(&gen->b);
	else if (ft_strcmp(op, "rra") == 0)
		r_rotate(&gen->a);
	else if (ft_strcmp(op, "rrb") == 0)
		r_rotate(&gen->b);
}
