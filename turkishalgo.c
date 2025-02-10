/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkishalgo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:41:27 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/10 10:18:54 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	max(t_general *gen)
{
	t_list	*i;
	t_list	*j;
	int		number;

	i = gen->b;
	while (i)
	{
		j = gen->b;
		while (j)
		{
			if (i->data < j->data)
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

void	turkishalgo(t_general *gen)
{
	int	len;
	int	numberb;
	int	numbera;

	swap_op(gen, "pb", 1);
	len = sl(gen->a);
	if (len > 3)
		swap_op(gen, "pb", 1);
	while (sl(gen->a) > 3)
	{
		numbera = functionindexpush(gen, 0);
		numberb = functionnumberfindb(numbera, gen->b, 0);
		funtionpush(gen, numberb, numbera, 1);
	}
	three(gen);
	numbera = functionindexpush(gen, 0);
	funtionpush(gen, max(gen), numbera, 0);
	while (gen->b != NULL)
	{
		numbera = functionnumberfinda(gen->b->data, gen->a, 0);
		funtionpush(gen, gen->b->data, numbera, 2);
	}
	while (min(gen) != gen->a->data)
		swap_op(gen, "rra", 1);
}
