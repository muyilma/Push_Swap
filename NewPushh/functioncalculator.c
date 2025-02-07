#include "push_swap.h"


int functionOp(t_general *gen, t_list *list, int index, char *op)
{
	char *r;
	char *rr;
	int i;
	i = 0;
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
	if (stacklen(list) / 2 >= index)
	{
		swap_op(gen, r, 0);
		i++;
	}
	else if (stacklen(list) / 2 < index)
	{
		swap_op(gen, rr, 0);
		i++;
	}
	return (i);
}
int functionIndex(t_list *b,int number)
{
	int i;
	i=1;
	while (b->data != number)
	{
		i++;
		b = b->next;
	}
	return i;
}

int funtionNumberUp(t_general *gen, int numberb, int numbera, int indexa)
{
	t_general *cpygen;
	int indexb;
	int i;
	i = 0;
	cpygen = listcopy(gen);
	indexb = functionIndex(cpygen->b,numberb);
	if (!(stacklen(cpygen->a) % 2 == 0))
		indexa--;
	while (cpygen->a->data != numbera || cpygen->b->data != numberb)
	{
		if ((stacklen(cpygen->a) / 2 >= indexa && stacklen(cpygen->b) / 2 >= indexb) && (cpygen->b->data != numberb && cpygen->a->data != numbera))
			i+=swap_op(cpygen, "rr", 0);
		else if ((stacklen(cpygen->a) / 2 < indexa && stacklen(cpygen->b) / 2 < indexb) && (cpygen->b->data != numberb && cpygen->a->data != numbera))
			i+=swap_op(cpygen, "rrr", 0);
		else if ((stacklen(cpygen->a) / 2 > indexa || stacklen(cpygen->a) / 2 <= indexa) && cpygen->a->data != numbera)
			i += functionOp(cpygen, cpygen->a, indexa, "a");

		else if ((stacklen(cpygen->b) / 2 > indexb || stacklen(cpygen->b) / 2 <= indexb) && cpygen->b->data != numberb)
			i += functionOp(cpygen, cpygen->b, indexb, "b");
	}    
    allfree(cpygen);
	return (i);
}
int functionNumberFindB(int number, t_list *b, int min)
{
	int smallnumber;
	int bignumber;

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

int functionIndexPush(t_general *gen,int minIndex)
{
	int number;
	int index;
	int i;
	int j;
	t_list *a;
	j = 2147483647;
	index = 1;
	a = gen->a;
	i=0;
	while (a != NULL)
	{
		number = functionNumberFindB(a->data, gen->b, 0);
		i += funtionNumberUp(gen, number, a->data, index);
		if (i < j)
		{
			j = i;
			minIndex = a->data;
		}
		index++;
		i = 0;
		a = a->next;
	}
	return (minIndex);
}



//int functionIndexPush(t_general *gen,int minIndex)
//{
//	int number;
//	int index;
//	int i;
//	int j;
//	t_list *a;
//	j = 2147483647;
//	index = 1;
//	a = gen->a;
//	i=0;
//	while (a != NULL)
//	{
//		number = functionNumberFindB(a->data, gen->b, 0);
//		i += funtionNumberUp(gen, number, a->data, index);
//		if (i < j)
//		{
//			j = i;
//			minIndex = index;
//		}
//		index++;
//		i = 0;
//		a = a->next;
//	}
//	return (minIndex);
//}

