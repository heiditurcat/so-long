/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:44:40 by hturcat           #+#    #+#             */
/*   Updated: 2023/03/03 14:02:34 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nb, char format)
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
		len += ft_print_hexa((nb / 16), format);
		len += write (1, &str[nb % 16], 1);
	}
	return (len);
}
