.PHONY: all, bonus, clean, fclean, re
NAME = libftprintf.a

FT_PRINTF_FUNC =	ft_print_c.c ft_print_di.c ft_print_hex.c\
					ft_print_p.c ft_print_percentage.c	ft_print_s.c ft_print_unsignedint.c
LIBFT_FUNC		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
					ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
					ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_FILES_WITH_PATH = $(addprefix srcs/, $(FT_PRINTF_FUNC))
LIBFT_FILES_WITH_PATH = $(addprefix libft/, $(LIBFT_FUNC))

OBJ = $(SRC_FILES_WITH_PATH:%.c=%.o) $(LIBFT_FILES_WITH_PATH:%.c=%.o) ft_printf.o

all: $(NAME)
	@echo "$(NAME) completed!"

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) 

%.o: %.c
	cc -Wall -Werror -Wextra -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)	

re: fclean all