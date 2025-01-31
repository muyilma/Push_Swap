NAME=push_swap

SRCS= control.c error.c push_swap.c sorting.c swap_op.c

LIBFT=libft/libft.a

CFLAGS= -Wall -Werror -Wextra
CC = cc

all: $(NAME)


$(NAME): $(SRCS)
	make -C ./libft -s
	cc  -g -o $(NAME)  $(CFLAGS) $(SRCS)  $(LIBFT) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re