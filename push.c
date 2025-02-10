/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:13:59 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/10 10:18:36 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	functionop(t_general *gen, t_list *list, int index, char *op)
{
	char	*r;
	char	*rr;

	if (ft_strcmp("a", op) == 0)
	{
		r = "ra";
		rr = "rra";
	}
	else
	{
		r = "rb";
		rr = "rrb";
	}
	if (sl(list) / 2 >= index)
		swap_op(gen, r, 1);
	else if (sl(list) / 2 < index)
		swap_op(gen, rr, 1);
}

void	pusher(t_general *gen, int push)
{
	if (push == 1)
		swap_op(gen, "pb", 1);
	else if (push == 2)
		swap_op(gen, "pa", 1);
}

void	funtionpush(t_general *gen, int numberb, int numbera, int push)
{
	t_list	*b;
	t_list	*a;
	int		indexb;
	int		indexa;

	a = gen->a;
	b = gen->b;
	indexa = functionindex(a, numbera) - 1;
	indexb = functionindex(b, numberb) - 1;
	while (gen->a->data != numbera || gen->b->data != numberb)
	{
		if ((sl(gen->a) / 2 >= indexa && sl(gen->b) / 2 >= indexb)
			&& (gen->b->data != numberb && gen->a->data != numbera))
			swap_op(gen, "rr", 1);
		else if ((sl(gen->a) / 2 < indexa && sl(gen->b) / 2 < indexb)
			&& (gen->b->data != numberb && gen->a->data != numbera))
			swap_op(gen, "rrr", 1);
		else if ((sl(gen->a) / 2 > indexa || sl(gen->a) / 2 <= indexa)
			&& gen->a->data != numbera)
			functionop(gen, gen->a, indexa, "a");
		else if ((sl(gen->b) / 2 > indexb || sl(gen->b) / 2 <= indexb)
			&& gen->b->data != numberb)
			functionop(gen, gen->b, indexb, "b");
	}
	pusher(gen, push);
}

int	functionnumberfinda(int number, t_list *b, int min)
{
	int	smallnumber;
	int	bignumber;

	smallnumber = 2147483647;
	bignumber = 2147483647;
	while (b != NULL)
	{
		if (number < b->data)
		{
			if (smallnumber > b->data)
			{
				smallnumber = b->data;
				min++;
			}
		}
		else
		{
			if (bignumber > b->data)
				bignumber = b->data;
		}
		b = b->next;
	}
	if (min > 0)
		return (smallnumber);
	return (bignumber);
}
