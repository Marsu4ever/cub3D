NAME=cube3d

LIBMLX_PATH = ../includes/MLX42

LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a

LIBFT_PATH = ../includes/libft

LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

HEADERS = -I ../incudes -I $(LIBMLX_PATH)/include/ -I "/Users/$(USER)/.brew/opt/glfw/include"

LIBS = $(LIBFT) $(LIBMLX) -L/Users/$(USER)/.brew/lib/ -ldl -lglfw -pthread -lm

SRCS = \
	main.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(LIBMLX) $(SRCS) $(OBJS)
	cd ../includes/libft && $(MAKE) && make
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