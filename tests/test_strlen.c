/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:15:28 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 21:26:34 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_strlen(char *str)
{
	static int	test_nbr;
	int			ret_lib;
	int			ret_ft;
	int			ret;

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	ret_lib = strlen(str);
	ret_ft = ft_strlen(str);
	printf("string           : >|%s|<\n", str);
	printf("RETURN strlen    : %d\n", ret_lib);
	printf("RETURN ft_strlen : %d\n", ret_ft);
	if (ret_lib == ret_ft)
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}
