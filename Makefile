NAME = cub3d
SRCS = $(shell find . -path $(MLX_DIR) -prune -o \
					  -path $(LIB_DIR) -prune -o \
					  -path ./subproject -prune -o \
					  -type f -name "*.c" -print)

OBJS = $(SRCS:.c=.o)
# 상대경로일 경우, make가 변환을 제대로 처리해주지 못한다.
DEPS = $(SRCS:.c=.d)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./utils/libft
MLX_DIR = ./mlx
# MLX_DIR = ./mlx_cs
INC = ./includes
TAGS = -framework OpenGL -framework AppKit -fsanitize=address 
# TAGS =  -lmlx -lXext -lX11 -fsanitize=address -lm -lmlx

all: $(NAME)

$(DEP_DIR):
	mkdir -p $(DEP_DIR)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	echo $(DEPS)
	$(CC) $^ -L$(LIB_DIR) -L$(MLX_DIR) -lft -lmlx -o $@ $(TAGS)

-include $(DEPS)

%.o: %.c $(SRCS)
	$(CC) $(CFLAGS) -c $< -I$(MLX_DIR) -I$(INC) -o $@

$(DEP_DIR)%.d: %.c
	$(CC) -MMD -c $< -I$(MLX_DIR) -I$(INC) -MF $@

clean:
	make clean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJS) $(DEPS)

fclean:
	make fclean -C $(LIB_DIR)
	make clean -C $(MLX_DIR)
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
