NAME=cube3d

LIBMLX_PATH = MLX42

LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

# CFLAGS =
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

HEADERS = -I includes -I $(LIBMLX_PATH)/include/MLX42 -I "/Users/$(USER)/.brew/opt/glfw/include" -I $(LIBFT_PATH)/headers

LIBS = $(LIBFT) $(LIBMLX) -L/Users/$(USER)/.brew/lib/ -ldl -lglfw -pthread -lm

SRCS = \
	src/main.c \
	src/parsing/check_file.c \
	src/parsing/check_if_closed.c \
	src/parsing/check_right.c \
	src/parsing/check_user_input.c \
	src/parsing/find_player_position.c \
	src/parsing/get_and_check_data.c \
	src/free_utils.c \
	src/parsing/get_colour.c \
	src/parsing/make_modify_and_check_map_1.c \
	src/parsing/make_modify_and_check_map_2.c \
	src/parsing/make_modify_and_check_map_3.c \
	src/parsing/read_file.c \
	src/run_wolfenstein.c \
	src/errors/errors.c \
	src/errors/error_message_selector.c \
	src/minimap.c \
	src/render.c \
	src/raycasting.c \
	src/parsing/parsing.c \
	src/parsing/parsing_utils_1.c \
	src/parsing/parsing_utils_2.c \
	src/parsing/compass.c \
	src/buildsomewalls.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBMLX):
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(LIBMLX) $(OBJS)
	cd $(LIBFT_PATH) && make
	cc $(CFLAGS) $(SRCS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX_PATH)/build
	cd $(LIBFT_PATH) && make clean

fclean: clean
	@rm -rf $(NAME)
	cd $(LIBFT_PATH) && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re