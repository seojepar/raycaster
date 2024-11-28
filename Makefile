NAME = cub3D
SRC = 	get_next_line.c			\
		error.c				\
		gnl_info.c				\
		is_id.c				\
		line.c					\
		line2.c				\
		ft_add_to_buffer.c	\
		ft_endswith.c			\
		ft_trim.c				\
		vector.c				\
		color.c						\
		events.c					\
		main.c						\
		map_parse.c					\
		map_save.c					\
		nonmap_parse.c				\
		nonmap_save.c				\
		parse.c						\
		render.c					\
		start.c						
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
DEPS = $(SRCS:.c=.d)
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs
LIB_DIR = libft
INC = ./includes/
TAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $^ -L$(LIB_DIR) -lft -lmlx -o $@ $(TAGS)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

%.d: %.c
	$(CC) -MMD  -I$(INC) -c $< -MF $@

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean:
	make fclean -C $(LIB_DIR)
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
