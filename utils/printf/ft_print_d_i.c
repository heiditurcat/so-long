/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:03:53 by hturcat           #+#    #+#             */
/*   Updated: 2023/03/03 14:00:42 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		len = 11;
	}
	else if (nb < 0)
	{
		len += ft_print_c('-');
		nb = -nb;
		len += ft_print_d_i(nb);
	}
	else if (nb > 9)
	{
		len += ft_print_d_i(nb / 10);
		len += ft_print_d_i(nb % 10);
	}
	else
		len += ft_print_c(nb + '0');
	return (len);
}
