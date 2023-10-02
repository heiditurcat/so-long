/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:34:22 by hturcat           #+#    #+#             */
/*   Updated: 2023/03/03 14:05:45 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_print_u(nb / 10);
		len += ft_print_u(nb % 10);
	}
	else
		len += ft_print_c(nb + '0');
	return (len);
}
