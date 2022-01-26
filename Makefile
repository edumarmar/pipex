NAME		=	pipex
SRC_A		=	sources/main.c sources/utils.c sources/exit.c

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

INC		=	-Iincludes -I$(LIBFT_DIR)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
CLIB	=	ar -rc
RM		=	rm -f

GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=address -g
endif

mandatory:	$(NAME)

$(NAME):
	@ $(MAKE) bonus DEBUG=$(DEBUG) -C ./libft
	@ $(CC) $(CFLAG) $(D_FLAG) $(SRC_A) $(INC) $(LIBFT) -o $(NAME)
	@printf "$(_SUCCESS) pipex ready.\n"

all:		$(NAME)

clean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)

fclean:
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

PHONY: all clean fclean re mandatory
