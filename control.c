#include "push_swap.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	ft_error(void)
{
	write(1, "error", 5);
	_exit(1);
}

void	ft_digit(char *str)
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
			ft_error();
	}
}

void	repaet(char **av, char *ac)
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
			ft_error();
		i++;
	}
}

void	control(int ac, char **av)
{
	int	j;

	j = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		j = -1;
	}
	while (av[j])
	{
		while (av[++j])
		{
			ft_digit(av[j]);
			repaet(av, av[j]);
			printf("%d\n", ft_atoi(av[j]));
		}
	}
}
