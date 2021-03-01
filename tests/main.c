/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:57:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/28 21:30:01 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_suit(char *ft_name, int total, int result)
{
	printf("\n%s=> Tests %s: ", C_BOLD, ft_name);
	if (result < total)
		printf("%s%i failed%s, ",
			C_ERROR, total - result, C_END);
	if (result > 0)
		printf("%s%i passed%s, ",
			C_SUIT_OK, result, C_END);
	printf("%i total\n", total);
}

void	test_str(char *argv, int (*test)(char *), char *ft_name)
{
	int		total;
	int		result;
	char	long_str[1024];

	print_ft_title(ft_name);
	total = 7;
	result = 0;
	memset(long_str, '.', 1024);
	long_str[1023] = '\0';
	result += test("Hello, world!");
	result += test("");
	result += test(long_str);
	result += test("Some special characters 你好世界!");
	result += test("\ttabulation");
	result += test("\0");
	result += test("42\0this should not be here");
	test_suit(ft_name, total, result);
	if (!strcmp(argv, "all"))
		print_continue();
}

int		main(int argc, char *argv[])
{
	if (argc == 2 && (!strcmp(argv[1], "all") ||
		!strcmp(argv[1], "ft_read") || !strcmp(argv[1], "ft_write") ||
		!strcmp(argv[1], "ft_strcpy") || !strcmp(argv[1], "ft_strcmp") ||
		!strcmp(argv[1], "ft_strlen") || !strcmp(argv[1], "ft_strdup")))
	{
		if (!strcmp(argv[1], "ft_strlen") || !strcmp(argv[1], "all"))
			test_str(argv[1], test_strlen, "ft_strlen");
		if (!strcmp(argv[1], "ft_strcpy") || !strcmp(argv[1], "all"))
			test_str(argv[1], test_strcpy, "ft_strcpy");
		if (!strcmp(argv[1], "ft_strcmp") || !strcmp(argv[1], "all"))
			test_strcmp(argv[1]);
		if (!strcmp(argv[1], "ft_write") || !strcmp(argv[1], "all"))
			test_str(argv[1], test_write, "ft_write");
		if (!strcmp(argv[1], "ft_read") || !strcmp(argv[1], "all"))
			test_read();
		printf("\n");
	}
	else
		printf("\n%sERROR:%s %s\n\n", C_ERROR, C_END, ERR_MSG);
	return (0);
}
