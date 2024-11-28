NAME = cub3d
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
		map_check.c					\
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
MLX_DIR = mlx
INC = ./includes/
TAGS = -framework OpenGL -framework AppKit -fsanitize=address 

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	echo $(DEPS)
	$(CC) $^ -L$(LIB_DIR) -L$(MLX_DIR) -lft -lmlx -o $@ $(TAGS)

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(INC) -c $< -o $@

%.d: %.c
	$(CC) -MMD -I$(MLX_DIR) -I$(INC) -c $< -MF $@

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean:
	make fclean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
