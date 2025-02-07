#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_general *listcopy(t_general *gen)
{
	t_general *cpygen;
	t_list *a;
	t_list *b;

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

int max(t_general *gen)
{
	t_list *i;
	t_list *j;
	int number;

	i = gen->b;
	while (i)
	{
		j = gen->b;
		while (j)
		{
			if (i->data < j->data)
				break;
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
void turkishalgo(t_general *gen)
{
	int len;
	int indexpush;
	int numberb;

	swap_op(gen, "pb", 1);
	len = stacklen(gen->a);
	if (len > 3)
		swap_op(gen, "pb", 1);
	while (stacklen(gen->a) > 3)
	{
		indexpush = functionIndexPush(gen, 0);
		numberb = functionNumberFindB(indexpush, gen->b, 0);
		funtionPush(gen, numberb, indexpush, 1);
	}
	three(gen);
	indexpush = functionIndexPush(gen, 0);
	funtionPush(gen, max(gen), indexpush, 0);
	while (gen->b != NULL)
	{

		indexpush = functionNumberFindA(gen->b->data, gen->a, 0);
		funtionPush(gen, gen->b->data, indexpush, 2);
	}
	while (min(gen)!=gen->a->data)
		swap_op(gen,"rra",1);
}
