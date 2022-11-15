/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:55:47 by lliberal          #+#    #+#             */
/*   Updated: 2022/11/15 23:08:43 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_prnt
{
	va_list	*args;
	char	*format;
}			t_prnt;

int	ft_printf(const	char *format, ...);
int	ft_putchar_counter(char *str);
int	conversion_int(int p, char *base, int size_base);

#endif
