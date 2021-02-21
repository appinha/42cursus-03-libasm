/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:57:20 by apuchill          #+#    #+#             */
/*   Updated: 2021/02/21 11:15:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>

int		main(void)
{
	char	text[14] = "Hello, world!\n";

	printf("%zu\n", ft_strlen(text));
	return (0);
}
