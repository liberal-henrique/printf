/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:13:01 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/22 23:32:32 by lliberal         ###   ########.fr       */
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

int	convert_pointer(uintptr_t p, char *base, uintptr_t size_base, int flag)
{
	int	count;

	count = 0;
	if (p == 0)
		return (ft_putstr_counter("(nil)"));
	if (flag++ == 0)
		count = ft_putstr_counter("0x");
	if (p >= size_base)
		count += convert_pointer(p / size_base, base, size_base, flag++);
	count += write(1, &base[(p) % (size_base)], 1);
	flag++;
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
	return (write(1, &c, 1));
}
