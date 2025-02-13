/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:03:42 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 13:46:46 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_error(char **av, int sp)
{
	int	j;

	j = 0;
	while (av[++j] && sp == 1)
		free(av[j]);
	if (sp == 1)
		free(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error2(char **av, int sp)
{
	int	j;

	j = 0;
	while (av[++j] && sp == 1)
		free(av[j]);
	if (sp == 1)
		free(av);
	exit(0);
}
