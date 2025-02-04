#include "push_swap.h"



void	turkishalgo(t_general *gen)
{
	int len;
	swap_op(gen, "pb", 1);
	len = stacklen(gen->a);
	if (len > 3)
		swap_op(gen, "pb", 1);
}
