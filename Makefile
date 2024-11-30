NAME = cub3D
SRC =  color.c \
		events.c \
		is_id.c \
		line_utiils.c \
		main.c \
		parse_map.c \
		ray_cast.c \
		save_texture.c \
		vector.c \
		error.c \
		get_next_line.c \
		line_gnl.c \
		line_utils2.c \
		parse.c \
		parse_texture.c \
		save_map.c \
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
