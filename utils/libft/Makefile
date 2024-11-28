SRCS = $(shell find . -type f -name "*.c" -print)
OBJS = $(SRCS:.c=.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = ../../includes

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $(NAME) $^

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -I$(INC) -o $@

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all


.PHONY: all bonus clean fclean re
