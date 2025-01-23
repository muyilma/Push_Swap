#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*front_add(t_list **lst, int content)
{
	t_list	*newstr;

	newstr = malloc(sizeof(size_t));
	newstr->data = content;
	if (!*lst)
	{
		*lst = malloc(sizeof(t_list));
		*lst = newstr;
	}
	else
	{
		newstr->next = *lst;
		*lst = newstr;
	}
	return (*lst);
}
t_list	*back_add(t_list **lst, int content)
{
	t_list	*newstr;

	newstr = *lst;
	if (!*lst)
	{
		*lst = malloc(sizeof(t_list));
		newstr = malloc(sizeof(t_list));
		newstr->data = content;
		*lst = newstr;
	}
	else
	{
		while (newstr->next != NULL)
			newstr = newstr->next;
		newstr->next = malloc(sizeof(t_list));
		newstr->next->data = content;
	}
	return (*lst);
}

void	print(t_list *a)
{
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}

t_general	*stackadd(int ac, char **av)
{
	t_general	*gen;
	int			i;

	gen = malloc(sizeof(t_general));
	i = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		av[0] = "0";
	}
	if (av[2] != NULL)
	{
		while (av[++i])
			gen->a = back_add(&gen->a, ft_atoi(av[i], av));
	}
	return (gen);
}

int	main(int ac, char **av)
{
	t_general	*gen;

	control(ac, av);
	gen = stackadd(ac, av);
	
	print(gen->a);
}
