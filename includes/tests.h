/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 08:08:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 11:41:20 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libasm.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define C_END		"\033[0m"
# define C_BOLD		"\033[1m"
# define C_FT_NAME	"\033[38;5;13m"
# define C_TITLE	"\033[38;5;75m"
# define C_TEST		"\033[38;5;199m"
# define C_TEST_OK	"\033[1m\033[42m"
# define C_TEST_FA	"\033[1m\033[41m"
# define C_SUIT_OK	"\033[1;32m"
# define C_ERROR	"\033[1;31m"
# define C_WARNING	"\033[1;33m"
# define L_TEST		"• • • • • • • • • • • • • • • • •"
# define ERR_MSG	"Please provide a valid testing option - e.g. all, ft_read"
# define CONT_MSG	"\nPress ENTER to continue to next Test Suit\n"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
void	test_suit(char *ft_name, int total, int result);

void	test_str(char *argv, int (*test)(char *), char *ft_name);
void	test_read(void);
void	test_write(char *argv);
int		test_strlen(char *str);
int		test_strcpy(char *src);
int		test_strdup(char *str);
void	test_strcmp(char *argv);

void	print_ft_title(char *ft_name);
void	print_test_title(int test_nbr);
int		print_test_passed(void);
int		print_test_failed(void);
void	print_continue(void);

#endif
