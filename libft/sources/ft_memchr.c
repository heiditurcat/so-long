/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:06:10 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:15:07 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	i;
	unsigned char	*ptr;
	unsigned char	cnew;

	i = 0;
	cnew = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == cnew)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
