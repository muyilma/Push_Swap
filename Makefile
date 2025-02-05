NAME=push_swap

SRCS= control.c error.c push_swap.c sorting.c swap_op.c turkishalgo.c

LIBFT=libft/libft.a

CFLAGS= 
CC = cc

all: $(NAME)


$(NAME): $(SRCS)
	make -C ./libft -s
	cc  -g -o $(NAME)  $(CFLAGS) $(SRCS)  $(LIBFT) 

clean:
	make clean -C ./libft -s
	

fclean: clean
	make fclean -C ./libft -s
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re