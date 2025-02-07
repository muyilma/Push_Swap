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
	write(1, "error", 5);
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

int	ft_atoi(const char *str, char **av)
{
	long result;
	long sign;

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
	}
	result = sign * result;
	if (!(result >= -2147483648 && result <= 2147483647))
		ft_error(av, 0);
	int n = result;
	return (n);
}