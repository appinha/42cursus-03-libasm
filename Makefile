# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:56:04 by apuchill          #+#    #+#              #
#    Updated: 2021/02/16 15:58:40 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

DIR_SRCS	= srcs
DIR_OBJS	= objs

SRCS		= $(foreach dir, $(DIR_SRCS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INCLUDES	= -I includes

ASM			= nasm
ASM_FLAGS	= -f elf64

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -lasm -g3 -fsanitize=address

RM			= /bin/rm -f

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.s
			@mkdir -p $(DIR_OBJS)
			@$(ASM) $(ASM_FLAGS) $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)
			$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
