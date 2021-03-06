/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:15:28 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 13:31:12 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_strlen(char *str)
{
	static int	test_nbr;
	int			ret_lib;
	int			ret_ft;
	int			ret;

	test_nbr += 1;
	print_test_title(test_nbr);
	ret_lib = strlen(str);
	ret_ft = ft_strlen(str);
	printf("%sINPUT            :%s >|%s|<\n", C_TITLE, C_END, str);
	printf("%sRETURN strlen    :%s %d\n", C_TITLE, C_END, ret_lib);
	printf("%sRETURN ft_strlen :%s %d\n", C_TITLE, C_END, ret_ft);
	if (ret_lib == ret_ft)
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}
