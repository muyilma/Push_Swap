#include "push_swap.h"

int functionNumberFindA(int number, t_list *b, int min)
{
	int smallnumber;
	int bignumber;

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