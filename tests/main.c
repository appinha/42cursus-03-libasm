/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:57:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/22 08:23:09 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_title(char *ft_name)
{
	printf("\n%s• %s%s\n", C_FT_NAME, ft_name, C_END);
}

int		main(void)
{
	char	txt_1[14] = "Hello, world!\n";
	char	txt_2[14] = "";

	print_title("ft_strlen");
	printf("%zu\n", ft_strlen(txt_1));
	printf("%zu\n", ft_strlen(txt_2));

	print_title("ft_write");
	ft_write(1, txt_1, ft_strlen(txt_1));
	ft_write(1, txt_2, ft_strlen(txt_2));
	printf("\n");

	return (0);
}
