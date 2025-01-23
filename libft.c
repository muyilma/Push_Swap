#include <stdlib.h>
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != 0 || s1[i] != 0))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(const char *str,char **av)
{
	long	result;
	long	sign;

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
	result=sign*result;
	if (!(result >= -2147483648 && result <= 2147483647))
		ft_error(av,0);//burada leak var
	int n = result;
	return (n);
}

void	*ft_calloc(size_t count, size_t size)
{
	int *a;
	size_t len;
	size_t i;
	unsigned char *s;

	len = count * size;
	i = 0;
	a = malloc(count * size);
	if (a == NULL)
		return (NULL);
	s = (unsigned char *)a;
	while (i < len)
	{
		*(s + i) = 0;
		i++;
	}
	return (a);
}