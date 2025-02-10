/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musyilma <musyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:16:36 by musyilma          #+#    #+#             */
/*   Updated: 2025/02/10 17:52:47 by musyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

void				swap_op(t_general *gen, char *op, int print);
t_list				*front_add(t_list **lst, int content);
void				control(int ac, char **av, int i, int sp);
void				ft_error(char **av, int sp);
void				ft_error2(char **av, int sp);
void				ft_error3(char **av, int sp);
void				control_bonus(int ac, char **av, int i, int sp);
void				sorting(t_general *gen);
void				turkishalgo(t_general *gen);
int					sl(t_list *lst);
int					functionindexpush(t_general *gen, int minIndex);
int					functionindex(t_list *b, int number);
int					functionnumberfindb(int number, t_list *b, int min);
void				funtionpush(t_general *gen, int numberb, int numbera,
						int push);
void				allfree(t_general *gen);
void				three(t_general *gen);
t_list				*back_add(t_list *lst, int content);
t_general			*stackadd(int ac, char **av, t_general *gen);
int					functionnumberfinda(int number, t_list *b, int min);
t_list				*back_add(t_list *lst, int content);

#endif