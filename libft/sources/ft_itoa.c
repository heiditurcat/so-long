/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <hturcat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:31:31 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/22 10:55:09 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		n = n * -1;
	while (n != '\0')
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	int			i;
	long int	nb;
	char		*str;

	nb = n;
	i = 0;
	size = ft_size(nb);
	if (nb < 0 || n == 0)
		size++;
	str = (char *)ft_calloc (sizeof(char), size + 1);
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
		i++;
	}
	while (size-- > i)
	{
		str[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
