NAME=cube3d

LIBMLX_PATH = MLX42

LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

HEADERS = -I includes -I $(LIBMLX_PATH)/include/MLX42 -I "/Users/$(USER)/.brew/opt/glfw/include" -I $(LIBFT_PATH)/headers

LIBS = $(LIBFT) $(LIBMLX) -L/Users/$(USER)/.brew/lib/ -ldl -lglfw -pthread -lm

SRCS = \
	src/main.c \
	src/parsing/check_file.c \
	src/parsing/check_if_closed.c \
	src/parsing/check_right.c \
	src/parsing/check_user_input.c \
	src/parsing/find_player_position.c \
	src/free_utils.c \
	src/parsing/get_colour.c \
	src/parsing/modify_and_check_map.c \
	src/parsing/read_file.c \
	src/mlx_functions.c \
	src/errors/errors.c \
	src/render.c \
	src/raycasting.c \
	src/parsing/parsing.c \
	src/parsing/parsing_utils.c \
	src/parsing/compass.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBMLX):
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(LIBMLX) $(SRCS) $(OBJS)
	cd $(LIBFT_PATH) && $(MAKE) && make
	cc $(CFLAGS) $(HEADERS) $(SRCS) $(LIBS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX_PATH)/build
	cd $(LIBFT_PATH) && make clean

fclean: clean
	@rm -rf $(NAME)
	cd $(LIBFT_PATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libmlx