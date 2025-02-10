/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:09:29 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/10 19:34:26 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_error_bonus(t_general *gen, char *str)
{
	write(2, "Error\n", 6);
	free(str);
	allfree(gen);
	exit(1);
}

int	listsorting(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	readmove(t_general *gen, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_op(gen, "sa", 0);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_op(gen, "sb", 0);
	else if (ft_strcmp(op, "pa\n") == 0)
		swap_op(gen, "pa", 0);
	else if (ft_strcmp(op, "pb\n") == 0)
		swap_op(gen, "pb", 0);
	else if (ft_strcmp(op, "ra\n") == 0)
		swap_op(gen, "ra", 0);
	else if (ft_strcmp(op, "rb\n") == 0)
		swap_op(gen, "rb", 0);
	else if (ft_strcmp(op, "rr\n") == 0)
		swap_op(gen, "rr", 0);
	else if (ft_strcmp(op, "rra\n") == 0)
		swap_op(gen, "rra", 0);
	else if (ft_strcmp(op, "rrb\n") == 0)
		swap_op(gen, "rrb", 0);
	else if (ft_strcmp(op, "rrr\n") == 0)
		swap_op(gen, "rrr", 0);
	else
		ft_error_bonus(gen, op);
}

void	sortingchecker(t_general *gen)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		readmove(gen, str);
		free(str);
	}
	if (listsorting(gen->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_general	*gen;

	control_bonus(ac, av, 0, 0);
	if (ac == 2)
		return (0);
	gen = malloc(sizeof(t_general));
	gen->a = NULL;
	gen->b = NULL;
	gen = stackadd(ac, av, gen);
	sortingchecker(gen);
	allfree(gen);
}
