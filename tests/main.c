/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:57:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 11:40:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void		test_read(void)
{
	char	buff[1024];
	int		i;

	print_ft_title("ft_read");
	i = 3;
	while (i > 0)
	{
		memset(buff, 0, 1024);
		printf("\nPlease write some characters and press ENTER\n");
		write(1, "INPUT          : ", 17);
		ft_read(0, buff, 1024);
		printf("OUTPUT ft_read : %s", buff);
		i--;
	}
}

static void		test_str(void (*test)(char *), char *ft_name)
{
	char	long_str[1024];

	print_ft_title(ft_name);
	memset(long_str, '.', 1024);
	long_str[1023] = '\0';
	test("Hello, world!");
	test("Some special characters 你好世界!");
	test("");
	test("\ttabulation");
	test("\0");
	test("42\0this should not be here");
	test(long_str);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (strcmp(argv[1], "all") == 0)
		{
			test_read();
			test_str(test_write, "ft_write");
			test_str(test_strlen, "ft_strlen");
			test_str(test_strcpy, "ft_strcpy");
		}
		else if (strcmp(argv[1], "ft_read") == 0)
			test_read();
		else if (strcmp(argv[1], "ft_write") == 0)
			test_str(test_write, argv[1]);
		else if (strcmp(argv[1], "ft_strlen") == 0)
			test_str(test_strlen, argv[1]);
		else if (strcmp(argv[1], "ft_strcpy") == 0)
			test_str(test_strcpy, argv[1]);
		else
			printf("\n%sERROR:%s %s\n\n", C_ERROR, C_END, ERR_MSG);
	}
	else
		printf("\n%sERROR:%s %s\n\n", C_ERROR, C_END, ERR_MSG);
	return (0);
}
