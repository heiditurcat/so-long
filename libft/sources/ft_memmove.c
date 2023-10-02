/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:07:59 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:26:40 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*newdest;
	const char	*newsrc;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	newdest = dest;
	newsrc = src;
	if (newdest > newsrc)
	{
		while (n-- > 0)
			newdest[n] = newsrc[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			newdest[i] = newsrc[i];
			i++;
		}
	}
	return (dest);
}
