/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:23:46 by hturcat           #+#    #+#             */
/*   Updated: 2023/03/03 14:04:14 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexaptr(unsigned long long nb, char format)
{
	char	*str;
	int		len;

	len = 0;
	if (format == 'x')
		str = "0123456789abcdef";
	else if (format == 'X')
		str = "0123456789ABCDEF";
	if (nb <= 15)
		len += write (1, &str[nb], 1);
	else if (nb > 15)
	{
		len += ft_print_hexaptr((nb / 16), format);
		len += write (1, &str[nb % 16], 1);
	}
	return (len);
}

int	ft_print_p(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_print_hexaptr(ptr, 'x');
	return (len);
}
