/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 21:16:04 by apuchill          #+#    #+#             */
/*   Updated: 2021/03/06 13:18:13 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	test_fd(int fd_1, int fd_2)
{
	int		ret;
	int		ret_ft[2];
	int		errno_ft[2];
	char	buff[2][218];

	memset(buff[0], 0, 218);
	memset(buff[1], 0, 218);
	ret_ft[0] = read(fd_1, buff[0], 217);
	errno_ft[0] = errno;
	ret_ft[1] = ft_read(fd_2, buff[1], 217);
	errno_ft[1] = errno;
	printf("%sINPUT  fd      :%s %i\n", C_TITLE, C_END, fd_1);
	printf("%sOUTPUT read    :%s >|%s|<\n", C_TITLE, C_END, buff[0]);
	printf("%sOUTPUT ft_read :%s >|%s|<\n", C_TITLE, C_END, buff[1]);
	printf("%sRETURN read    :%s %i\n", C_TITLE, C_END, ret_ft[0]);
	printf("%sRETURN ft_read :%s %i\n", C_TITLE, C_END, ret_ft[1]);
	printf("%sERRNO  read    :%s %i\n", C_TITLE, C_END, errno_ft[0]);
	printf("%sERRNO  ft_read :%s %i\n", C_TITLE, C_END, errno_ft[1]);
	if (ret_ft[0] == ret_ft[1] && errno_ft[0] == errno_ft[1])
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}

static void	print_msg(void)\
{
	printf("%sPlease write some characters and then press ENTER%s\n",
			C_WARNING, C_END);
	write(1, "\033[38;5;75mINPUT          :\033[0m ", 32);
}

static int	test_stdin(void)
{
	char	buff[2][1024];
	int		ret_ft[2];
	int		errno_ft[2];
	int		ret;

	memset(buff[0], 0, 1024);
	memset(buff[1], 0, 1024);
	print_msg();
	ret_ft[0] = read(0, buff[0], 1024);
	errno_ft[0] = errno;
	print_msg();
	ret_ft[1] = ft_read(0, buff[1], 1024);
	errno_ft[1] = errno;
	printf("\n%sOUTPUT read    :%s %s", C_TITLE, C_END, buff[0]);
	printf("%sOUTPUT ft_read :%s %s", C_TITLE, C_END, buff[1]);
	printf("%sRETURN read    :%s %i\n", C_TITLE, C_END, ret_ft[0]);
	printf("%sRETURN ft_read :%s %i\n", C_TITLE, C_END, ret_ft[1]);
	printf("%sERRNO  read    :%s %i\n", C_TITLE, C_END, errno_ft[0]);
	printf("%sERRNO  ft_read :%s %i\n", C_TITLE, C_END, errno_ft[1]);
	if (ret_ft[0] == ret_ft[1] && errno_ft[0] == errno_ft[1])
		ret = print_test_passed();
	else
		ret = print_test_failed();
	return (ret);
}

static int	test(int type)
{
	static int	test_nbr;
	int			fd[2];
	int			ret;

	test_nbr += 1;
	print_test_title(test_nbr);
	if (type == 0)
	{
		fd[0] = open("tests/input.txt", O_RDONLY);
		fd[1] = open("tests/input.txt", O_RDONLY);
		if (!fd[0] || !fd[1])
		{
			printf("%sError: unable to open file.%s\n\n", C_ERROR, C_END);
			return (1);
		}
		else
			ret = test_fd(fd[0], fd[1]);
		close(fd[0]);
		close(fd[1]);
	}
	if (type == 1)
		ret = test_fd(-1, -1);
	if (type == 2)
		ret = test_stdin();
	return (ret);
}

void		test_read(void)
{
	int		total;
	int		result;
	int		i;

	print_ft_title("ft_read");
	total = 5;
	result = 0;
	result += test(0);
	result += test(1);
	i = 3;
	while (i-- > 0)
		result += test(2);
	test_suit("ft_read", total, result);
}
