/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:11:40 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/16 23:44:35 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char fmt, va_list args)
{
	int	count;

	count = 0;
	if (fmt == 'c')
		count = ft_putchar_counter(va_arg(args, int));
	if (fmt == '%')
		count = ft_putchar_counter('%');
	if (fmt == 'd' || fmt == 'i')
		count = convert(va_arg(args, int), "0123456789", 10);
	if (fmt == 'u')
		count = convert(va_arg(args, unsigned int), "0123456789", 10);
	if (fmt == 'x')
		count = convert(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (fmt == 'X')
		count = convert(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	if (fmt == 's')
		count = ft_putstr_counter(va_arg(args, char *));
	if (fmt == 'p')
		count = ft_pointer(va_arg(args, uintptr_t));
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
			count += ft_check(format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
