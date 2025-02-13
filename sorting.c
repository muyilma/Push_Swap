/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:18:35 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 19:10:14 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sl(t_list *lst)
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

static int	check(t_general *gen)
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
		else if (lst->data > lst->next->next->data)
			swap_op(gen, "ra", 1);
		lst = gen->a;
		if (check(gen) == 1)
			break ;
		else if (lst->data > lst->next->next->data)
			swap_op(gen, "ra", 1);
		if (check(gen) == 1)
			break ;
		else if (lst->data > lst->next->data)
			swap_op(gen, "sa", 1);
		if (check(gen) == 1)
			break ;
		swap_op(gen, "rra", 1);
		lst = gen->a;
	}
}

void	sorting(t_general *gen)
{
	int	len;

	len = sl(gen->a);
	if (len == 2)
		swap_op(gen, "sa", 1);
	else if (len == 3)
		three(gen);
	else if (len > 3)
		turkishalgo(gen);
}
