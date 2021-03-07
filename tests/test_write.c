/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:14:55 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 20:42:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	test_fd(char *str, int fd_1, int fd_2)
{
	int		ret_ft[2];
	int		errno_ft[2];
	int		ret;

	ret_ft[0] = write(fd_1, str, strlen(str));
	errno_ft[0] = errno;
	ret_ft[1] = ft_write(fd_2, str, strlen(str));
	errno_ft[1] = errno;
	printf("%sINPUT  fd #1   :%s %i\n", C_TITLE, C_END, fd_1);
	printf("%sINPUT  fd #2   :%s %i\n", C_TITLE, C_END, fd_2);
	printf("%sRETURN write    :%s %i\n", C_TITLE, C_END, ret_ft[0]);
	printf("%sRETURN ft_write :%s %i\n", C_TITLE, C_END, ret_ft[1]);
	printf("%sERRNO  write    :%s %i\n", C_TITLE, C_END, errno_ft[0]);
	printf("%sERRNO  ft_write :%s %i\n", C_TITLE, C_END, errno_ft[1]);
	if (ret_ft[0] == ret_ft[1] && errno_ft[0] == errno_ft[1])
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}

static int	test_stdout(char *str)
{
	int			ret_ft[2];
	int			errno_ft[2];
	int			ret;

	printf("%sINPUT  fd       :%s %i\n", C_TITLE, C_END, 1);
	write(1, "\033[38;5;75mOUTPUT write    :\033[0m >|", 35);
	ret_ft[0] = write(1, str, strlen(str));
	errno_ft[0] = errno;
	write(1, "|<\n\033[38;5;75mOUTPUT ft_write :\033[0m >|", 38);
	ret_ft[1] = ft_write(1, str, strlen(str));
	errno_ft[1] = errno;
	write(1, "|<", 2);
	printf("\n%sRETURN write    :%s %i\n", C_TITLE, C_END, ret_ft[0]);
	printf("%sRETURN ft_write :%s %i\n", C_TITLE, C_END, ret_ft[1]);
	printf("%sERRNO  write    :%s %i\n", C_TITLE, C_END, errno_ft[0]);
	printf("%sERRNO  ft_write :%s %i\n", C_TITLE, C_END, errno_ft[1]);
	if (ret_ft[0] == ret_ft[1] && errno_ft[0] == errno_ft[1])
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}

static int	test(char *str, int type)
{
	static int	test_nbr;
	int			ret;
	int			fd[2];

	test_nbr += 1;
	print_test_title(test_nbr);
	if (type == 0)
	{
		ret = test_stdout(str);
		test_nbr += 1;
		print_test_title(test_nbr);
		fd[0] = open("tests/out_lib.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
		fd[1] = open("tests/out_ft.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
		if (!fd[0] || !fd[1])
			printf("%sError: unable to open file.%s\n\n", C_ERROR, C_END);
		else
		{
			ret += test_fd(str, fd[0], fd[1]);
			close(fd[0]);
			close(fd[1]);
		}
	}
	else
		ret = test_fd(str, -1, -1);
	return (ret);
}

void		test_write(char *argv)
{
	int		total;
	int		result;
	char	long_str[1024];

	print_ft_title("ft_write");
	total = 2 * 7 + 1;
	result = 0;
	memset(long_str, '.', 1024);
	long_str[1023] = '\0';
	result += test("Hello, world!", 0);
	result += test("", 0);
	result += test(long_str, 0);
	result += test("Some special characters 你好世界!", 0);
	result += test("\ttabulation", 0);
	result += test("\0", 0);
	result += test("42\0this should not be here", 0);
	result += test("", 1);
	test_suit("ft_write", total, result);
	if (!strcmp(argv, "all"))
		print_continue();
}
