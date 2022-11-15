/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:13:01 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/15 21:43:57 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_int(int p, char *base, int size_base)
{
	int	count;

	count = 0;
	if (p >= size_base)
		count = conversion_int(p / size_base, base, size_base);
	count += write(1, &base[p % size_base], 1);
	return (count);
}
