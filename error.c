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
	int j;

	j = 0;
	while (av[++j] && sp == 1)
		free(av[j]);
	if (sp == 1)
		free(av);
	exit(0);
}