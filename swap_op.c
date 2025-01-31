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

void	push(t_list **a, t_list **b, char *op, int p)
{
	t_list	*temp;

	temp = *a;
	*b = front_add(b, temp->data);
	temp = temp->next;
	free(*a);
	*a = temp;
	if (p == 1)
	{
		write(1, op, 2);
		write(1, "\n", 1);
	}
}

void	rotate(t_list **a, char *op, int p)
{
	t_list	*temp;
	t_list	*head;
	t_list	*last;

	last = *a;
	last = last->next;
	head = *a;
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = head;
	head->next = NULL;
	head = last;
	*a = head;
	if (p == 1)
	{
		write(1, op, 2);
		write(1, "\n", 1);
	}
}

void	r_rotate(t_list **a, char *op, int p)
{
	t_list	*temp;
	t_list	*head;
	t_list	*last;

	temp = *a;
	head = *a;
	last = NULL;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
		{
			last = temp->next;
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	last->next = head;
	head = last;
	*a = head;
	if (p == 1)
	{
		write(1, op, 3);
		write(1, "\n", 1);
	}
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
		push(&gen->a, &gen->b, op, print);
	else if (ft_strcmp(op, "pa") == 0)
		push(&gen->b, &gen->a, op, print);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(&gen->a, op, print);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(&gen->b, op, print);
	else if (ft_strcmp(op, "rra") == 0)
		r_rotate(&gen->a, op, print);
	else if (ft_strcmp(op, "rrb") == 0)
		r_rotate(&gen->b, op, print);
}
