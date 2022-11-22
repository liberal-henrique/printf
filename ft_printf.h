/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:55:47 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/22 23:32:51 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef unsigned long long	t_ull;

int	ft_putstr_counter(char *str);
int	ft_putchar_counter(char c);
int	convert_pointer(uintptr_t p, char *base, uintptr_t size_base, int flag);
int	convert(double p, char *base, double size_base);
int	ft_printf(const	char *format, ...);

#endif
