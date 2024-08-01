NAME=cube3d

LIBMLX_PATH = MLX42

LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

HEADERS = -I includes -I $(LIBMLX_PATH)/include/MLX42 -I "/Users/$(USER)/.brew/opt/glfw/include" -I $(LIBFT_PATH)/headers

LIBS = $(LIBFT) $(LIBMLX) -L/Users/$(USER)/.brew/lib/ -ldl -lglfw -pthread -lm

SRCS = \
	src/main.c\
	src/calc_and_make_map.c\
	src/mlx_functions.c\
	src/errors/errors.c\

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