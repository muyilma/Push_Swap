#include "push_swap.h"

int functionOp2(t_general *gen, t_list *list, int index, char *op)
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
		swap_op(gen, r, 1);
		i++;
	}
	else if (stacklen(list) / 2 < index)
	{
		swap_op(gen, rr, 1);
		i++;
	}
	return (i);
}

void funtionPush(t_general *gen, int numberb, int numbera,int push)
{
	t_list *b;
	t_list *a;
	a = gen->a;
	b = gen->b;
	int indexb;
	int indexa;
	indexa = functionIndex(a, numbera);
	indexb = functionIndex(b, numberb);
	if (!(stacklen(gen->a) % 2 == 0))
		indexa--;
	while (gen->a->data != numbera || gen->b->data != numberb)
	{
		if ((stacklen(gen->a) / 2 >= indexa && stacklen(gen->b) / 2 >= indexb) && (gen->b->data != numberb && gen->a->data != numbera))
			swap_op(gen, "rr", 1);
		else if ((stacklen(gen->a) / 2 < indexa && stacklen(gen->b) / 2 < indexb) && (gen->b->data != numberb && gen->a->data != numbera))
			swap_op(gen, "rrr", 1);
		else if ((stacklen(gen->a) / 2 > indexa || stacklen(gen->a) / 2 <= indexa) && gen->a->data != numbera)
			functionOp2(gen, gen->a, indexa, "a");
		else if ((stacklen(gen->b) / 2 > indexb || stacklen(gen->b) / 2 <= indexb) && gen->b->data != numberb)
			functionOp2(gen, gen->b, indexb, "b");
	}
    if(push==1)
	    swap_op(gen, "pb", 1);
    else if(push==2)
	    swap_op(gen, "pa", 1);
}

