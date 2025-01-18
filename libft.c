#include <stdlib.h>

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

int	ft_atoi(const char *str)
{
	int	i;
	int	val;
	int	a;

	i = 0;
	val = 0;
	a = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
	{
		a *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = (str[i] - 48) + (10 * val);
		i++;
	}
	return (val * a);
}


void	*ft_calloc(size_t count, size_t size)
{
	int				*a;
	size_t			len;
	size_t			i;
	unsigned char	*s;

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