# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 23:40:02 by sbednar           #+#    #+#              #
#    Updated: 2019/01/27 09:14:07 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libft.a

INC_DIR	=	./inc
OBJ_DIR	=	./obj
SRC_DIR	=	./src

SRC		= 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstadd_back.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_islower.c \
			ft_isupper.c \
			ft_isstn.c \
			ft_putwchar.c \
			ft_putwchar_fd.c \
			ft_strallcpy.c \
			ft_nbrlen.c \
			ft_wordlen.c \
			ft_wordscnt.c \
			ft_strsfree.c \
			ft_lstdels.c \
			ft_lstdelones.c \
			get_next_line.c
OBJ		=	$(SRC:.c=.o)

OBJS	=	$(addprefix $(OBJ_DIR)/, $(OBJ))

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJ_DIR)
	@echo "\033[32m\033[1m--->create archive:\033[0m"
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR):
	@echo "\033[32m\033[1m--->create obj directory:\033[0m"
	mkdir -p $(OBJ_DIR)
	@echo "\033[32m\033[1m--->compile sources:\033[0m"
	@$(MAKE) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean:
	@$(MAKE) clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
