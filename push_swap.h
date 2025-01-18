typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_general
{
	t_list			*a;
	t_list			*b;
}					t_general;

#include <stddef.h>

void				swap_op(t_general *gen, char *op, int print);
t_list				*front_add(t_list **lst, int content);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
void				*ft_calloc(size_t count, size_t size);