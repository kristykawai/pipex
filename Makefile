#SETUP
NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h 
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

SRCS	=	pipex.c utils.c
SRC_DIR	=	src/
SRC_PATH		=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ		=	$(SRC_PATH:.c=.o)

#LIBRARY
LIBFTPRINTF_PATH = lib/libft
LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -L$(LIBFTPRINTF_PATH) -lft -o $(NAME)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"


all:			$(NAME)

clean:
				@$(RM) $(OBJ)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m