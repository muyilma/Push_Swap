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

int				swap_op(t_general *gen, char *op, int print);
t_list				*front_add(t_list **lst, int content);
int					ft_atoi(const char *str, char **av);
char				**ft_split(char const *s, char c);
void				control(int ac, char **av);
void				ft_error(char **av, int sp);
void				ft_error2(char **av, int sp);
void				sorting(t_general *gen);
void				allfree(t_general *gen);
void				turkishalgo(t_general *gen);
int					stacklen(t_list *lst);
int functionIndexPush(t_general *gen,int minIndex);
t_general *listcopy(t_general *gen);
int functionIndex(t_list *b,int number);
int functionNumberFindB(int number, t_list *b, int min);
void funtionPush(t_general *gen, int numberb, int numbera,int push);
void	three(t_general *gen);
int functionNumberFindA(int number, t_list *b, int min);
int	min(t_general *gen);
// REMOVE
t_list				*back_add(t_list *lst, int content);
void				print(t_list *a);