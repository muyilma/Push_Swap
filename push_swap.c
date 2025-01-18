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

void	print(t_list *a)
{
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}

t_general	*control(int ac, char **av)
{
	t_general	*gen;
	int			i;
	int			j;
	char		*str;

	gen = malloc(sizeof(t_general));
	i = 1;
	j = 0;
	if (ac == 2)
	{
		while (av[j] )
		{
			gen->a = front_add(&gen->a, ft_atoi(ft_split(av[i], ' ')[j]));
			j++;
		}
	}
	// else if (ac > 2)
	// {
	// 	while (av[++i])
	// 		gen->a = front_add(&gen->a, ft_atoi(av[i]));
	// }
	return (gen);
}

int	main(int ac, char **av)
{
	t_general	*gen;

	gen = control(ac, av);
	print(gen->a);
}
