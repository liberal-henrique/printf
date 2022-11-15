/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:11:40 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/15 23:08:33 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putchar_counter(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

int	ft_check(const char fmt, va_list args)
{
	int	count;

	count = 0;
	if (fmt == 'd' || fmt == 'i')
		count = conversion_int(va_arg(args, int), "0123456789", 10);
	if (fmt == 's')
		count = ft_putchar_counter(va_arg(args, char *));
	return (count);
}


int	conversion_int(int p, char *base, int size_base)
{
	int	count;

	count = 0;
	if (p >= size_base)
		count = conversion_int(p / size_base, base, size_base);
	count += write(1, &base[p % size_base], 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count = ft_check(format[i], args);
		}
		else
			count = write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("INICIO: %s\n", "Luiz Henrique");
	printf("INICIO: %s\n", "Luiz Henrique");
	return (0);
}

//printf("%i\n", 10);
