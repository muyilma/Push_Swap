#include "push_swap.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi2(const char *str, char **av, int sp)
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
		if (!(result >= -2147483648 && result <= 2147483647))
			ft_error(av, sp);
	}
	result = sign * result;
	if (!(result >= -2147483648 && result <= 2147483647))
		ft_error(av, sp);
	n = result;
	return (n);
}

void	ft_digit(char *str, char **av, int sp)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
			+ 1] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			ft_error(av, sp);
	}
}

void	repaet(char **av, char *ac, int sp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (ft_strcmp(av[i], ac) == 0)
			j++;
		if (j == 2)
			ft_error(av, sp);
		i++;
	}
}
void	sort(char **av, int sp)
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

void	control(int ac, char **av)
{
	int	j;
	int	sp;

	sp = 0;
	j = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		av[0] = "0";
		sp++;
	}
	while (av[j])
	{
		while (av[++j])
		{
			ft_digit(av[j], av, sp);
			repaet(av, av[j], sp);
		}
	}
	sort(av, sp);
	j = 0;
	while (av[++j] && sp == 1)
		free(av[j]);
	if (sp == 1)
		free(av);
}
