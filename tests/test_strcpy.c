/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:16:36 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 13:09:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_strcpy(char *src)
{
	static int	test_nbr;
	char		ret_lib[1024];
	char		ret_ft[1024];
	int			ret;

	test_nbr += 1;
	print_test_title(test_nbr);
	strcpy(ret_lib, src);
	ft_strcpy(ret_ft, src);
	printf("%sRETURN strcpy    :%s >|%s|<\n", C_TITLE, C_END, ret_lib);
	printf("%sRETURN ft_strcpy :%s >|%s|<\n", C_TITLE, C_END, ret_ft);
	if (strcmp(ret_lib, ret_ft) == 0)
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}
