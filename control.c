/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:01:52 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/11 13:00:34 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	ft_atoi2(const char *str, char **av, int sp)
{
	long	result;
	long	sign;
	int		n;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (!(result > -2147483648 && result < 2147483649))
			ft_error(av, sp);
	}
	result = sign * result;
	if (!(result >= -2147483648 && result <= 2147483647))
		ft_error(av, sp);
	n = result;
	return (n);
}

static void	ft_digit(char *str, char **av, int sp)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			ft_error(av, sp);
	}
}

static void	repeat(char **av, char *ac, int sp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) == ft_atoi(ac))
			j++;
		if (j == 2)
			ft_error(av - 1, sp);
		i++;
	}
}

static void	sort(char **av, int sp)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (av[i])
	{
		j = 0;
		while (av[j + i])
		{
			if (ft_atoi2(av[i], av, sp) <= ft_atoi2(av[j + i], av, sp))
				j++;
			else
			{
				j++;
				k++;
			}
		}
		i++;
	}
	if (k == 0)
		ft_error2(av, sp);
}

void	control(int ac, char **av, int i, int sp)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		av[0] = "0";
		sp++;
		if (av == NULL)
			ft_error2(av, sp);
	}
	while (av[i])
	{
		while (av[++i])
		{
			ft_digit(av[i], av, sp);
			repeat(av + 1, av[i], sp);
		}
	}
	sort(av, sp);
	i = 0;
	while (av[++i] && sp == 1)
		free(av[i]);
	if (sp == 1)
		free(av);
}
