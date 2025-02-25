/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:19:41 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 09:52:55 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	swap(t_list *gen, char *op, int p)
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

static void	push(t_list **a, t_list **b, char *op, int p)
{
	t_list	*temp;

	if ((*a) == NULL)
		return ;
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

static void	rotate(t_list **a, char *op, int p)
{
	t_list	*head;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	*a = head->next;
	head->next = NULL;
	last->next = head;
	if (p == 1)
	{
		write(1, op, 2);
		write(1, "\n", 1);
	}
}

static void	r_rotate(t_list **a, char *op, int p)
{
	t_list	*temp;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next)
		temp = temp->next;
	last = temp;
	temp = *a;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
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
	else if (ft_strcmp(op, "pb") == 0)
		push(&gen->a, &gen->b, op, print);
	else if (ft_strcmp(op, "pa") == 0)
		push(&gen->b, &gen->a, op, print);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(&gen->a, op, print);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(&gen->b, op, print);
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(&gen->b, op, print);
		rotate(&gen->a, op, 0);
	}
	else if (ft_strcmp(op, "rra") == 0)
		r_rotate(&gen->a, op, print);
	else if (ft_strcmp(op, "rrb") == 0)
		r_rotate(&gen->b, op, print);
	else if (ft_strcmp(op, "rrr") == 0)
	{
		r_rotate(&gen->b, op, print);
		r_rotate(&gen->a, op, 0);
	}
}
