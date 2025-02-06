#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*front_add(t_list **lst, int content)
{
	t_list	*newstr;

	newstr = malloc(sizeof(t_list));
	newstr->data = content;
	newstr->next = NULL;
	if (!*lst)
	{
		*lst = newstr;
	}
	else
	{
		newstr->next = *lst;
		*lst = newstr;
	}
	return (*lst);
}

t_list	*back_add(t_list *lst, int content)
{
	t_list	*newlst;

	newlst = lst;
	if (!lst)
	{
		lst = malloc(sizeof(t_list));
		lst->data = content;
		lst->next = NULL;
	}
	else
	{
		while (newlst->next != NULL)
			newlst = newlst->next;
		newlst->next = malloc(sizeof(t_list));
		newlst->next->data = content;
		newlst->next->next = NULL;
	}
	return (lst);
}

void	print(t_list *a)
{
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}

t_general	*stackadd(int ac, char **av, t_general *gen)
{
	int	i;
	int	sp;

	i = 0;
	sp = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		av[0] = "0";
		sp++;
	}
	if (av[2] != NULL)
	{
		while (av[++i])
			gen->a = back_add(gen->a, ft_atoi(av[i], av));
	}
	i = 0;
	while (av[++i] && sp == 1)
		free(av[i]);
	if (sp == 1)
		free(av);
	return (gen);
}

void	allfree(t_general *gen)
{
	t_list	*temp;

	temp = gen->a;
	if (temp)
	{
		while (temp)
		{
			temp = temp->next;
			free(gen->a);
			gen->a = temp;
		}
	}
	temp = gen->b;
	if (temp)
	{
		while (temp)
		{
			temp = temp->next;
			free(gen->b);
			gen->b = temp;
		}
	}
	free(gen);
}

int	main(int ac, char **av)
{
	t_general	*gen;

	control(ac, av);
	gen = malloc(sizeof(t_general));
	gen->a = NULL;
	gen->b = NULL;
	gen = stackadd(ac, av, gen);
	swap_op(gen,"pb",1);
	swap_op(gen,"pb",1);
	swap_op(gen,"pb",1);
	swap_op(gen,"pb",1);
	swap_op(gen,"pb",1);
	swap_op(gen,"pb",1);
	sorting(gen);
	print(gen->a);
	allfree(gen);
}
