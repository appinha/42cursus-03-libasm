/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:34:26 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/05 20:00:31 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_ft_title(char *ft_name)
{
	printf("\n\n %s%s  %s  %s%s\n", C_FT_NAME, L_TEST, ft_name, L_TEST, C_END);
}

void	print_test_title(int test_nbr)
{
	printf("\n%s• Test #%i%s\n", C_TEST, test_nbr, C_END);
}

int		print_test_passed(void)
{
	printf("%s PASS %s\n", C_TEST_OK, C_END);
	return (1);
}

int		print_test_failed(void)
{
	printf("%s FAIL %s\n", C_TEST_FA, C_END);
	return (-1);
}

void	print_continue(void)
{
	char	buff[1024];

	printf("%s%s%s", C_WARNING, CONT_MSG, C_END);
	read(0, buff, 1024);
}
