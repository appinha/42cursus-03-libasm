/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:14:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 21:15:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		test_write(char *str)
{
	static int	test_nbr;
	int			ret_ft[2];
	int			errno_ft[2];
	int			ret;

	test_nbr = test_nbr + 1;
	print_test_title(test_nbr);
	write(1, "OUTPUT write     : >|", 21);
	ret_ft[0] = write(1, str, strlen(str));
	errno_ft[0] = errno;
	write(1, "|<\nOUTPUT ft_write  : >|", 24);
	ret_ft[1] = ft_write(1, str, strlen(str));
	errno_ft[1] = errno;
	write(1, "|<", 2);
	printf("\nRETURN write     : %i\n", ret_ft[0]);
	printf("RETURN ft_write  : %i\n", ret_ft[1]);
	printf("ERRNO write      : %i\n", errno_ft[0]);
	printf("ERRNO ft_write   : %i\n", errno_ft[1]);
	if (ret_ft[0] == ret_ft[1] && errno_ft[0] == errno_ft[1])
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}
