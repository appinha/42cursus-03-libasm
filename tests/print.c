/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:34:26 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 11:44:31 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_test_title(int test_nbr)
{
	printf("\n%s   Test #%i%s\n", C_TEST, test_nbr, C_END);
}

void	print_ft_title(char *ft_name)
{
	printf("\n %s%s  %s  %s%s\n", C_FT_NAME, L_TEST, ft_name, L_TEST, C_END);
}

void	print_test_passed(void)
{
	printf("%s=> Passed%s\n", C_TEST_OK, C_END);
}

void	print_test_failed(void)
{
	printf("%s=> Failed%s\n", C_ERROR, C_END);
}
