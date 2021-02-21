# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:56:04 by apuchill          #+#    #+#              #
#    Updated: 2021/02/21 11:39:16 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
TEST		= test.out

DIR_SRCS	= srcs
DIR_OBJS	= objs
DIR_TEST	= tests

SRCS		= ft_strlen.s
OBJS		= $(patsubst %.s, ${DIR_OBJS}/%.o, ${SRCS})
TEST_SRCS		= $(foreach dir, $(DIR_TEST), $(wildcard $(dir)/*.c))

INCLUDES	= -I includes

ASM			= nasm
ASM_FLAGS	= -f elf64

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -lasm -L . -g3 -fsanitize=address

RM			= /bin/rm -f

all:		$(NAME)

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.s
			@mkdir -p $(DIR_OBJS)
			@$(ASM) $(ASM_FLAGS) $< -o $@

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

test:		$(NAME) $(TEST_SRCS)
			@$(CC) $(TEST_SRCS) $(CFLAGS) $(INCLUDES) -o $(TEST)
			./$(TEST)

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME) $(TEST)

re:			fclean all

.PHONY:		all clean fclean re
