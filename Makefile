NAME := fdf
CC := cc
CFLAGS := -Wall -Wextra -Werror -I
RM := rm -f
RMDIR := rm -rf

SRC_DIR := src
OBJ_DIR := obj
INCLUDE := include
LIBFT_DIR := libft
GET_NEXT_LINE_DIR := get_next_line
MINILIBX_DIR := mlx_linux

SRCFILES := additional_libft.c \
            color.c \
		    draw.c \
		    error.c \
		    hook.c \
		    init_map.c \
		    main.c \
		    transform.c \
		    transform2.c \
		    utils.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT := $(LIBFT_DIR)/libft.a
GET_NEXT_LINE := $(GET_NEXT_LINE_DIR)/libget_next_line.a
MINILIBX := $(MINILIBX_DIR)/libmlx_Linux.a

LIB_PATH := -L$(LIBFT_DIR) -L$(GET_NEXT_LINE_DIR) -L$(MINILIBX_DIR)
LIB_LINK := -lft -lget_next_line  -lmlx_Linux -lm -lXext -lX11
LIB := $(LIB_PATH) $(LIB_LINK)

all: $(NAME)

$(NAME): $(LIBFT) $(GET_NEXT_LINE) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE):
	$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MINILIBX_DIR):
	git clone https://github.com/42paris/minilibx-linux.git mlx_linux

$(MINILIBX): $(MINILIBX_DIR)
	$(MAKE) -C $(MINILIBX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RMDIR) $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all

.PHONY:	all clean fclean re
