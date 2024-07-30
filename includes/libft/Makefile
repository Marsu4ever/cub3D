SRC_FILES = char/ft_isalpha.c char/ft_isdigit.c char/ft_isalnum.c char/ft_isascii.c \
			char/ft_isprint.c char/ft_isspace.c char/ft_tolower.c char/ft_toupper.c \
			str/ft_strlen.c str/ft_strlcpy.c str/ft_strlcat.c str/ft_striteri.c \
			str/ft_strchr.c str/ft_strrchr.c str/ft_strncmp.c str/ft_strcmp.c str/ft_skip.c \
			str/ft_strnstr.c str/ft_atoi.c str/ft_strdup.c str/ft_substr.c str/ft_strjoin.c \
			str/ft_strtrim.c str/ft_split.c str/ft_itoa.c str/ft_strmapi.c str/ft_parse_substr.c \
			mem/ft_memset.c mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memchr.c \
			mem/ft_memcmp.c mem/ft_calloc.c \
			print/ft_putchar_fd.c print/ft_putstr_fd.c print/ft_putendl_fd.c print/ft_putnbr_fd.c \
			print/ft_psfd.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			quotes/ft_skipquotes.c quotes/quotes_handling.c
BSRC_FILES = lst/ft_lstnew_bonus.c lst/ft_lstadd_front_bonus.c lst/ft_lstsize_bonus.c \
			 lst/ft_lstlast_bonus.c lst/ft_lstadd_back_bonus.c lst/ft_lstdelone_bonus.c \
			 lst/ft_lstclear_bonus.c lst/ft_lstiter_bonus.c lst/ft_lstmap_bonus.c
HDR_FILES = headers/libft.h headers/get_next_line.h
OBJ_FILES = $(SRC_FILES:.c=.o)
BOBJ_FILES = $(BSRC_FILES:.c=.o)
NAME = libft.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

bonus: .bonus

.bonus: $(NAME) $(BOBJ_FILES)
	ar -rcs $(NAME) $(BOBJ_FILES)
	@touch .bonus

%.o: %.c $(HDR_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BOBJ_FILES)
	@rm -rf .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all
