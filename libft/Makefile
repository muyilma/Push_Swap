NAME=libft.a

SRCS= ft_strlen.c  ft_substr.c ft_split.c ft_strcmp.c ft_calloc.c ft_memset.c ft_bzero.c ft_atoi.c 

OBJS= $(SRCS:.c=.o)

CFLAGS= -Wall -Werror -Wextra
CC = cc

all: $(NAME)


$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re