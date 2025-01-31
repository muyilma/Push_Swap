#include "push_swap.h"
#include <stdio.h>

int	stacklen(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	check(t_general *gen)
{
	t_list	*lst;

	lst = gen->a;
	while (lst)
	{
		if (lst->next && lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	three(t_general *gen)
{
	t_list	*lst;

	lst = gen->a;
	while (1)
	{
		if (check(gen) == 1)
			break ;
		else if (lst->data > lst->next->data)
			swap_op(gen, "sa", 1);
		if (check(gen) == 1)
			break ;
		swap_op(gen, "rra", 1);
		if (check(gen) == 1)
			break ;
		lst = gen->a;
	}
}

int	min(t_general *gen)
{
	t_list	*i;
	t_list	*j;
	int		number;

	i = gen->a;
	while (i)
	{
		j = gen->a;
		while (j)
		{
			if (i->data > j->data)
				break ;
			j = j->next;
			if (!j)
			{
				number = i->data;
				return (number);
			}
		}
		i = i->next;
	}
	number = i->data;
	return (number);
}

void	four(t_general *gen)
{
	t_list	*lst;
	int		c;
	int		i;

	i = 0;
	lst = gen->a;
	c = min(gen);
	while (lst)
	{
		if (lst->data == c)
		{
			if (i == 0)
				swap_op(gen, "pb", 1);
			else if (i == 1)
			{
				swap_op(gen, "sa", 1);
				swap_op(gen, "pb", 1);
			}
			else if (i == 2)
			{
				swap_op(gen, "rra", 1);
				swap_op(gen, "rra", 1);
				swap_op(gen, "pb", 1);
			}
			else if (i == 3)
			{
				swap_op(gen, "rra", 1);
				swap_op(gen, "pb", 1);
			}
			break ;
		}
		lst = lst->next;
		i++;
	}
	three(gen);
	swap_op(gen, "pa", 1);
}

void	sorting(t_general *gen)
{
	int len;
	len = stacklen(gen->a);
	if (len == 2)
		swap_op(gen, "sa", 1);
	else if (len == 3)
		three(gen);
	else if (len == 4)
		four(gen);
}