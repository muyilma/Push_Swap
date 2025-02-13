NAME=push_swap
NAME_BONUS=checker

SRCS_BONUS= ft_checker.c control_bonus.c error.c listadd.c sorting.c turkishalgo.c functioncal.c push.c swap_op.c
SRCS=  error.c listadd.c sorting.c turkishalgo.c functioncal.c push.c swap_op.c push_swap.c control.c

LIBFT=libft/libft.a
CFLAGS=-Wall -Wextra -Werror




$(NAME): $(SRCS) 
	make -C ./libft -s
	cc  -o $(NAME) $(CFLAGS) $(SRCS)  $(LIBFT) 

$(NAME_BONUS):$(SRCS_BONUS)
	make -C ./libft -s
	cc -o $(NAME_BONUS) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) 

all: $(NAME) $(NAME_BONUS)

bonus:$(NAME_BONUS)

clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re