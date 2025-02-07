// void	three(t_general *gen)
// {
// 	t_list	*lst;

// 	lst = gen->a;
// 	while (1)
// 	{
// 		if (check(gen) == 1)
// 			break ;
// 		else if (lst->data > lst->next->data)
// 			swap_op(gen, "sa", 1);
// 		if (check(gen) == 1)
// 			break ;
// 		swap_op(gen, "rra", 1);
// 		if (check(gen) == 1)
// 			break ;
// 		lst = gen->a;
// 	}
// }


void	four(t_general *gen)
{
	t_list	*lst;
	int		c;
	int		i;

	i = 0;
	lst = gen->a;
	c = min(gen);
	while (lst)
	{
		if (lst->data == c)
		{
			if (i == 0)
				swap_op(gen, "pb", 1);
			else if (i == 1)
			{
				swap_op(gen, "sa", 1);
				swap_op(gen, "pb", 1);
			}
			else if (i == 2)
			{
				swap_op(gen, "rra", 1);
				swap_op(gen, "rra", 1);
				swap_op(gen, "pb", 1);
			}
			else if (i == 3)
			{
				swap_op(gen, "rra", 1);
				swap_op(gen, "pb", 1);
			}
			break ;
		}
		lst = lst->next;
		i++;
	}
	three(gen);
	swap_op(gen, "pa", 1);
}

----------------------------------------

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

int funtionNumberUp(t_general *gen, int numberb, int numbera, int indexa)
{
	t_general *cpygen;
	int indexb;
	int i;
	i = 0;
	cpygen = listcopy(gen);
	indexb = 1;
	while (cpygen->b->data != numberb)
	{
		indexb++;
		cpygen->b = cpygen->b->next;
	}
	cpygen = listcopy(gen);
	if (!(stacklen(gen->a) % 2 == 0))
		indexa--;
	while (gen->a->data != numbera || gen->b->data != numberb)
	{
		if ((stacklen(gen->a) / 2 >= indexa && stacklen(gen->b) / 2 >= indexb) && (gen->b->data != numberb && gen->a->data != numbera))
		{
			swap_op(gen, "rr", 0);
			i++;
		}
		else if ((stacklen(gen->a) / 2 < indexa && stacklen(gen->b) / 2 < indexb) && (gen->b->data != numberb && gen->a->data != numbera))
		{
			swap_op(gen, "rrr", 0);
			i++;
		}
		else if ((stacklen(gen->a) / 2 > indexa || stacklen(gen->a) / 2 <= indexa) && gen->a->data != numbera)
			i += functionOp(gen, gen->a, indexa, "a");

		else if ((stacklen(gen->b) / 2 > indexb || stacklen(gen->b) / 2 <= indexb) && gen->b->data != numberb)
			i += functionOp(gen, gen->b, indexb, "b");
	}
	gen->a = cpygen->a;
	gen->b = cpygen->b;

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

int functionIndexPush(t_general *gen)
{
	int number;
	int index;
	int minIndex;
	int i;
	int j;
	t_list *a;
	j = 10;
	minIndex = 0;
	index = 1;
	gen = listcopy(gen);
	a = gen->a;
	i=0;
	while (a != NULL)
	{
		number = functionNumberFindB(a->data, gen->b, 0);
		i += funtionNumberUp(gen, number, a->data, index);
		if (i < j)
		{
			j = i;
			minIndex = index;
		}
		index++;
		i = 0;
		a = a->next;
	}
	allfree(gen);
	return (minIndex);
}

void turkishalgo(t_general *gen)
{
	int len;
	int indexpush;

	len = stacklen(gen->a);
	//swap_op(gen, "pb", 1);
	//if (len > 3)
	//	swap_op(gen, "pb", 1);
	indexpush = functionIndexPush(gen);

	printf("PUSHINDEX=%d\n", indexpush);
}