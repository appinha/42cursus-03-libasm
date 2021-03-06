# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:56:04 by apuchill          #+#    #+#              #
#    Updated: 2021/03/06 12:50:50 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
TEST		= test.out

DIR_SRCS	= srcs
DIR_OBJS	= objs
DIR_TEST	= tests

SRCS		= ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s \
				ft_strdup.s
OBJS		= $(patsubst %.s, ${DIR_OBJS}/%.o, ${SRCS})
TEST_SRCS	= $(foreach dir, $(DIR_TEST), $(wildcard $(dir)/*.c))

INCLUDES	= -I includes

ASM			= nasm
ASM_FLAGS	= -f elf64

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -lasm -L .

RM			= /bin/rm -f
NORM		= ~/.norminette/norminette.rb

C_H_LINE	= "\033[38;5;43m"
C_H_TITLE	= "\033[1m\033[38;5;199m"
C_END		= "\033[0m"

all:		$(NAME)

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.s
			@mkdir -p $(DIR_OBJS)
			@$(ASM) $(ASM_FLAGS) $< -o $@

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

.PHONY: test
test:		$(NAME) $(TEST_SRCS)
			@$(CC) $(TEST_SRCS) $(CFLAGS) $(INCLUDES) -o $(TEST)
			@echo $(C_H_LINE) && cat $(DIR_TEST)/header_line1.txt && \
			echo $(C_H_TITLE) && cat $(DIR_TEST)/header_title.txt && \
			echo "\033[1m\033[38;5;23m42saopaulo" \
			$(C_H_LINE) && cat $(DIR_TEST)/header_line2.txt && echo $(C_END)

.PHONY: test_all
test_all:	test
			@./$(TEST) all

.PHONY: ft_strlen
ft_strlen:	test
			@./$(TEST) ft_strlen

.PHONY: ft_strdup
ft_strdup:	test
			@./$(TEST) ft_strdup

.PHONY: ft_strcpy
ft_strcpy:	test
			@./$(TEST) ft_strcpy

.PHONY: ft_strcmp
ft_strcmp:	test
			@./$(TEST) ft_strcmp

.PHONY: ft_write
ft_write:	test
			@./$(TEST) ft_write

.PHONY: ft_read
ft_read:	test
			@./$(TEST) ft_read

.PHONY: norm
norm:
			$(NORM) */*.h */*.c

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME) $(TEST)

re:			fclean all

.PHONY:		all clean fclean re
