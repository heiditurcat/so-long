/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:27:54 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:15:12 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*newdest;
	const char	*newsrc;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	newdest = dest;
	newsrc = src;
	i = 0;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return (dest);
}
