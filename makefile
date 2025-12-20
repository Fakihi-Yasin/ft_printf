CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_utils.c ft_printf.c
OBJS = $(SRCS:.c=.o)

DELETE = rm -f
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DELETE) $(OBJS)

fclean: clean
	$(DELETE) $(NAME)

re: fclean all

.PHONY:	clean