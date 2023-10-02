/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:21:11 by hturcat           #+#    #+#             */
/*   Updated: 2023/03/03 14:10:56 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, const char *format, int i)
{
	int	len;

	len = 0;
	if (format[i] == 'c')
		len += ft_print_c(va_arg(args, int));
	if (format[i] == 's')
		len += ft_print_s(va_arg(args, char *));
	if (format[i] == 'p')
		len += ft_print_p(va_arg(args, unsigned long long));
	if (format[i] == 'd' || format[i] == 'i')
		len += ft_print_d_i(va_arg(args, int));
	if (format[i] == 'u')
		len += ft_print_u(va_arg(args, unsigned int));
	if (format[i] == 'x' || format[i] == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), format[i]);
	if (format[i] == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start (args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_type(args, format, i);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	return (len);
	va_end (args);
}
