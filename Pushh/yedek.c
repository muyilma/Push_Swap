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
	if (stacklen(list) / 2 > index)
	{
		swap_op(gen, r, 1);
		i++;
	}
	else if (stacklen(list) / 2 < index)
	{
		printf("%d %d\n", stacklen(list) / 2, index);
		swap_op(gen, rr, 1);
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
	// printf("%d %d\n",stacklen(gen->a),stacklen(gen->a)/2);
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
		if (stacklen(gen->a) / 2 < indexa && stacklen(gen->b) / 2 < indexb)
		{
			swap_op(gen, "rr", 1);
			i++;
		}
		else if (stacklen(gen->a) / 2 > indexa && stacklen(gen->b) / 2 > indexb)
		{
			swap_op(gen, "rrr", 1);
			i++;
		}

		if ((stacklen(gen->a) / 2 > indexa || stacklen(gen->a) / 2 < indexa) && gen->a->data != numbera)
			i += functionOp(gen, gen->a, indexa, "a");

		if ((stacklen(gen->b) / 2 > indexb || stacklen(gen->b) / 2 < indexb) && gen->b->data != numberb)
			i += functionOp(gen, gen->b, indexb, "b");

		if (gen->a->data != numbera)
			gen->a = gen->a->next;
		if (gen->b->data != numberb)
			gen->b = gen->b->next;
	}
	printf("start\n");
	print(gen->a);
	printf("--\n");
	print(gen->b);
	printf("finish\n");
	gen->a = cpygen->a;
	gen->b = cpygen->b;
	return (1);
}