/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:42:46 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 11:51:03 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_list	*front_add(t_list **lst, int content)
{
	t_list	*newstr;

	newstr = malloc(sizeof(t_list));
	if (newstr == NULL)
		return (NULL);
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
		if (lst == NULL)
			return (NULL);
		lst->data = content;
		lst->next = NULL;
	}
	else
	{
		while (newlst->next != NULL)
			newlst = newlst->next;
		newlst->next = malloc(sizeof(t_list));
		if (newlst->next == NULL)
			return (NULL);
		newlst->next->data = content;
		newlst->next->next = NULL;
	}
	return (lst);
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
		if (av == NULL)
			ft_error2(av, sp);
	}
	if (av[2] != NULL)
	{
		while (av[++i])
			gen->a = back_add(gen->a, ft_atoi(av[i]));
	}
	while (av[--i] && sp == 1 && (i != 0 && !av[1]))
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
