/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:13:45 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 10:46:57 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_general	*gen;

	control(ac, av, 0, 0);
	gen = malloc(sizeof(t_general));
	if (gen == NULL)
		return (0);
	gen->a = NULL;
	gen->b = NULL;
	gen = stackadd(ac, av, gen);
	sorting(gen);
	allfree(gen);
}
