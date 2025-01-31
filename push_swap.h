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

#include "libft/libft.h"
#include <stddef.h>

void				swap_op(t_general *gen, char *op, int print);
t_list				*front_add(t_list **lst, int content);
int					ft_atoi(const char *str, char **av);
char				**ft_split(char const *s, char c);
void				control(int ac, char **av);
void				ft_error(char **av, int sp);
void				ft_error2(char **av, int sp);
void				sorting(t_general *gen);
void				allfree(t_general *gen);

// REMOVE

void				print(t_list *a);