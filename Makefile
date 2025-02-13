NAME=push_swap

SRCS=  error.c sorting.c turkishalgo.c functioncal.c push.c swap_op.c push_swap.c control.c

LIBFT=libft/libft.a
CFLAGS=-Wall -Wextra -Werror



all: $(NAME)


$(NAME): $(SRCS) 
	make -C ./libft -s
	cc  -o $(NAME) $(CFLAGS) $(SRCS)  $(LIBFT)  


clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re