/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:18:36 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 22:34:50 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_strdup(char *str)
{
	static int	test_nbr;
	char		*ret_lib;
	char		*ret_ft;
	int			ret;

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	ret_lib = strdup(str);
	ret_ft = ft_strdup(str);
	printf("RETURN strdup    : >|%s|<\n", ret_lib);
	printf("RETURN ft_strdup : >|%s|<\n", ret_ft);
	if (strcmp(ret_lib, ret_ft) == 0)
		ret = print_test_passed();
	else
		ret = print_test_failed();
	free(ret_lib);
	free(ret_ft);
	return (ret);
}
