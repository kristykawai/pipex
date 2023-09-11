.PHONY: all, bonus, clean, fclean, re

SCR =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_print_c.c ft_print_di.c ft_print_hex.c ft_print_p.c \
		ft_print_percentage.c	ft_print_s.c ft_print_unsignedint.c ft_printf.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c 

OBJ = $(SCR:%.c=%.o)
NAME = libft.a

all: $(NAME)
	echo "$(NAME) completed!"

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) 

%.o: %.c
	cc -Wall -Wextra -Werror -c $(SCR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)	

re: fclean all
