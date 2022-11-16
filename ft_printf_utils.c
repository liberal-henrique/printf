/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:13:01 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/16 23:30:26 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert(double p, char *base, double size_base)
{
	int	count;

	count = 0;
	if (p < 0 && write(1, "-", 1) && ++count)
		p = -p;
	if (p >= size_base)
		count += convert(p / size_base, base, size_base);
	count += write(1, &base[((t_ull)p) % (t_ull)size_base], 1);
	return (count);
}

int	ft_putstr_counter(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int	ft_putchar_counter(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_pointer(uintptr_t num)
{
	int	count;

	if (num == 0)
		return (ft_putstr_counter("(nil)"));
	count = ft_putstr_counter("0x");
	count += convert(num, "0123456789abcdef", 16);
	return (count);
}
