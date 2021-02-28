/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:45:41 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 11:11:29 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_write(char *str)
{
	static int	test_nbr;
	int			len;
	int			ret_lib;
	int			errno_lib;
	int			ret_ft;
	int			errno_ft;

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	len = strlen(str);
	write(1, "OUTPUT write     : >|", 21);
	ret_lib = write(1, str, len);
	errno_lib = errno;
	write(1, "|<\nOUTPUT ft_write  : >|", 24);
	ret_ft = ft_write(1, str, len);
	errno_ft = errno;
	write(1, "|<", 2);
	printf("\nRETURN write     : %i\n", ret_lib);
	printf("RETURN ft_write  : %i\n", ret_ft);
	printf("ERRNO write      : %i\n", errno_lib);
	printf("ERRNO ft_write   : %i\n", errno_ft);
	if (ret_lib == ret_ft && errno_lib == errno_ft)
		print_test_passed();
	else
		print_test_failed();
}

void	test_strlen(char *str)
{
	static int	test_nbr;
	int			ret_lib;
	int			ret_ft;

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	ret_lib = strlen(str);
	ret_ft = ft_strlen(str);
	printf("String           : >|%s|<\n", str);
	printf("RETURN strlen    : %d\n", ret_lib);
	printf("RETURN ft_strlen : %d\n", ret_ft);
	if (ret_lib == ret_ft)
		print_test_passed();
	else
		print_test_failed();
}

void	test_strcpy(char *src)
{
	static int	test_nbr;
	char		dst_lib[1024];
	char		dst_ft[1024];

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	strcpy(dst_lib, src);
	ft_strcpy(dst_ft, src);
	printf("RETURN strcpy    : >|%s|<\n", dst_lib);
	printf("RETURN ft_strcpy : >|%s|<\n", dst_ft);
	if (strcmp(dst_lib, dst_ft) == 0)
		print_test_passed();
	else
		print_test_failed();
}
