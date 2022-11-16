/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:25:49 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/16 23:56:14 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	main(int argc, char **argv)
{
	(void) argc;
	printf("%d\n", ft_printf("%p\n", argv));
	printf("%d\n", printf("%p\n", argv));
	printf("%d\n", ft_printf(" %p %p \n", LONG_MIN, LONG_MAX));
	printf("%d\n", printf(" %p %p \n", LONG_MIN, LONG_MAX));
	// printf("%d\n", ft_printf("%s\n", "Luiz Henrique"));
	// printf("%d\n", printf("%s\n", "Luiz Henrique"));
	printf("%d\n", ft_printf("%%\n"));
	printf("%d\n", printf("%%\n"));
	//printf("%d\n", ft_printf("%X\n", 105));
	//printf("%d\n", printf("%X\n", 105));
	//printf("%d\n", ft_printf("%x\n", 105));
	//printf("%d\n", printf("%x\n", 105));
	//printf("%d\n", ft_printf("%u\n", 105));
	//printf("%d\n", printf("%u\n", 105));
	return (0);
}
