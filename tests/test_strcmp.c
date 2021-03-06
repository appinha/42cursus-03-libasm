/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 13:09:27 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 13:29:59 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	normalize(int ret)
{
	if (ret > 0)
		ret = 1;
	if (ret < 0)
		ret = -1;
	return (ret);
}

static int	test(char *s1, char *s2)
{
	static int	test_nbr;
	int			ret_lib;
	int			ret_ft;
	int			ret;

	test_nbr += 1;
	print_test_title(test_nbr);
	ret_lib = normalize(strcmp(s1, s2));
	ret_ft = normalize(ft_strcmp(s1, s2));
	printf("%sINPUT  #1        :%s >|%s|<\n", C_TITLE, C_END, s1);
	printf("%sINPUT  #2        :%s >|%s|<\n", C_TITLE, C_END, s2);
	printf("%sRETURN strcmp    :%s %i\n", C_TITLE, C_END, ret_lib);
	printf("%sRETURN ft_strcmp :%s %i\n", C_TITLE, C_END, ret_ft);
	if (ret_lib == ret_ft)
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}

void		test_strcmp(char *argv)
{
	int		total;
	int		result;
	char	long_s1[1024];
	char	long_s2[1024];

	print_ft_title("ft_strcmp");
	total = 9;
	result = 0;
	memset(long_s1, '.', 1024);
	memset(long_s2, '.', 1024);
	long_s1[1023] = '\0';
	long_s2[1023] = '\0';
	result += test("", "");
	result += test("", "Bonjour le monde!");
	result += test("Hello, world!", "\0not to be compared");
	result += test(long_s1, long_s2);
	long_s1[2] = 'A';
	result += test(long_s1, long_s2);
	result += test("你好世界!", "你好世界!");
	result += test("42", "42");
	result += test("42", "21");
	result += test("21", "42");
	test_suit("ft_strcmp", total, result);
	if (!strcmp(argv, "all"))
		print_continue();
}
