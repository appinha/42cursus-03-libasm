/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 08:08:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 11:22:46 by apuchill         ###   ########.fr       */
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
# define C_FT_NAME	"\033[1m\033[38;5;75m"
# define C_TEST		"\033[1;34m"
# define C_TEST_OK	"\033[1;32m"
# define C_ERROR	"\033[1;31m"
# define L_TEST		"• • • • • • • • • • • • • • • • •"
# define ERR_MSG	"Please provide a valid testing option - e.g. all, ft_read"

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
void	print_ft_title(char *ft_name);
void	print_test_title(int test_nbr);
void	print_test_passed(void);
void	print_test_failed(void);

void	test_strlen(char *str);
void	test_strcpy(char *src);
void	test_write(char *str);

#endif
