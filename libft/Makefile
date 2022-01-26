# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edmartin <edmartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 11:03:25 by edmartin          #+#    #+#              #
#    Updated: 2021/11/12 12:10:17 by edmartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	./ft_atoi.c 		\
		./ft_itoa.c 		\
		./ft_putstr.c 		\
		./ft_putchar.c		\
		./ft_putnbr.c		\
		./ft_bzero.c 		\
		./ft_calloc.c 		\
 		./ft_isascii.c 		\
		./ft_isalpha.c 		\
 		./ft_isdigit.c 		\
		./ft_islower.c		\
		./ft_isalnum.c		\
 		./ft_isprint.c 		\
 		./ft_memcmp.c 		\
 		./ft_memcpy.c 		\
		./ft_memccpy.c 		\
		./ft_memmove.c 		\
		./ft_memchr.c 		\
		./ft_memset.c 		\
		./ft_putchar_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_putstr_fd.c 	\
		./ft_substr.c 		\
		./ft_strcat.c		\
		./ft_strchr.c		\
		./ft_strrchr.c		\
		./ft_strcpy.c		\
		./ft_striteri.c 	\
 		./ft_strjoin.c 		\
		./ft_split.c		\
		./ft_strlcpy.c 		\
		./ft_strlcat.c 		\
		./ft_strncmp.c 		\
		./ft_strmapi.c 		\
		./ft_strdup.c 		\
		./ft_strlen.c 		\
		./ft_strtrim.c		\
 		./ft_strnstr.c 		\
 		./ft_strupcase.c 	\
		./ft_toupper.c 		\
		./ft_tolower.c 		\
		./get_next_line.c

OBJS = $(SRC:.c=.o)

BONUS = ./ft_lstnew.c 		\
		./ft_lstadd_front.c \
		./ft_lstsize.c 		\
		./ft_lstlast.c 		\
		./ft_lstadd_back.c 	\
		./ft_lstdelone.c 	\
		./ft_lstclear.c 	\
		./ft_lstiter.c 		\
		./ft_lstmap.c 		\

BONUS_OBJS		= $(BONUS:.c=.o)


HDRS = -I libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
