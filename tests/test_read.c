/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:16:04 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 21:17:55 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_read(void)
{
	char	buff[1024];
	int		i;

	print_ft_title("ft_read");
	i = 3;
	while (i > 0)
	{
		memset(buff, 0, 1024);
		printf("\n%sPlease write some characters and then press ENTER%s\n",
				C_WARNING, C_END);
		write(1, "INPUT          : ", 17);
		ft_read(0, buff, 1024);
		printf("OUTPUT ft_read : %s", buff);
		i--;
	}
}
