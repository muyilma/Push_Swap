#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_general	*listcopy(t_general *gen)
{
	t_general	*cpygen;
	t_list		*a;
	t_list		*b;

	a = gen->a;
	b = gen->b;
	cpygen = malloc(sizeof(t_general));
	cpygen->a = NULL;
	cpygen->b = NULL;
	while (a != NULL)
	{
		cpygen->a = back_add(cpygen->a, a->data);
		a = a->next;
	}
	while (b != NULL)
	{
		cpygen->b = back_add(cpygen->b, b->data);
		b = b->next;
	}
	return (cpygen);
}
int	functionNumberFindB(int number, t_list *b, int min)
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

int	funtionNumberUp(t_general *gen, int numberb, int numbera, int indexa)
{
	t_general	*cpygen;
	int			indexb;
	int			len;

	cpygen = listcopy(gen);
	indexb = 1;
	// printf("%d %d\n",stacklen(gen->a),stacklen(gen->a)/2);
	while (cpygen->b->data != numberb)
	{
		indexb++;
		cpygen->b = cpygen->b->next;
	}
	if (!(stacklen(gen->a) % 2 == 0))
		indexa--;
	while (gen->a != numbera || gen->b != numberb)
	{
		if (gen->a)
	}
	if (stacklen(gen->a) / 2 < indexa)
	{
		while (gen->a->data != numbera)
		{
			swap_op(gen, "rra", 1);
		}
		gen->a = cpygen->a;
	}
	else
	{
		while (gen->a->data != numbera)
		{
			swap_op(gen, "ra", 1);
		}
		gen->a = cpygen->a;
	}
	return (1);
}

int	functionIndexPush(t_general *gen)
{
	int		number;
	int		index;
	int		i;
	t_list	*a;

	index = 1;
	gen = listcopy(gen);
	a = gen->a;
	while (a != NULL)
	{
		number = functionNumberFindB(a->data, gen->b, 0);
		i += funtionNumberUp(gen, number, a->data, index);
		index++;
		i = 0;
		a = a->next;
	}
	allfree(gen);
	return (1);
}

void	turkishalgo(t_general *gen)
{
	int	len;
	int	indexpush;

	len = stacklen(gen->a);
	swap_op(gen, "pb", 1);
	if (len > 3)
		swap_op(gen, "pb", 1);
	indexpush = functionIndexPush(gen);
}
