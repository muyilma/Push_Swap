/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functioncal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:20:18 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 09:55:30 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	functionindex(t_list *b, int number)
{
	int	i;

	i = 1;
	while (b->data != number)
	{
		i++;
		b = b->next;
	}
	return (i);
}

static int	functionmove(int i, int j)
{
	if (i >= 0 && j >= 0)
	{
		if (i < j)
			i = j;
	}
	else if (i < 0 && j >= 0)
	{
		i = i * -1;
		i = i + j;
	}
	else if (i >= 0 && j < 0)
	{
		j = j * -1;
		i = i + j;
	}
	else if (i < 0 && j < 0)
	{
		if (i > j)
			i = j;
		i = i * -1;
	}
	return (i);
}

static int	funtionnumberup(t_general *gen, int numberb, int indexa)
{
	int	indexb;
	int	a;
	int	b;
	int	move;

	a = 0;
	b = 0;
	indexb = functionindex(gen->b, numberb) - 1;
	if (sl(gen->a) / 2 >= indexa)
		a = (indexa);
	else if (sl(gen->a) / 2 < indexa)
		a = (indexa - sl(gen->a));
	if (sl(gen->b) / 2 >= indexb)
		b = (indexb);
	else if (sl(gen->b) / 2 < indexb)
		b = (indexb - sl(gen->b));
	move = functionmove(a, b);
	return (move);
}

int	functionnumberfindb(int number, t_list *b, int min)
{
	int	smallnumber;
	int	bignumber;

	smallnumber = -2147483648;
	bignumber = -2147483648;
	while (b != NULL)
	{
		if (number > b->data)
		{
			if (smallnumber < b->data)
			{
				smallnumber = b->data;
				min++;
			}
		}
		else
		{
			if (bignumber < b->data)
				bignumber = b->data;
		}
		b = b->next;
	}
	if (min > 0)
		return (smallnumber);
	return (bignumber);
}

int	functionindexpush(t_general *gen, int minnumber)
{
	int		numberb;
	int		index;
	int		move;
	int		minmove;
	t_list	*a;

	minmove = 2147483647;
	index = 1;
	a = gen->a;
	move = 0;
	while (a != NULL)
	{
		numberb = functionnumberfindb(a->data, gen->b, 0);
		move = funtionnumberup(gen, numberb, index - 1);
		if (move < minmove)
		{
			minmove = move;
			minnumber = a->data;
		}
		index++;
		a = a->next;
	}
	return (minnumber);
}
