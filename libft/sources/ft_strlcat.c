/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:06:43 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:18 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	if (!size && (!dst || !src))
		return (0);
	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	while (dstlen + i + 1 < size && (src[i]))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (size <= dstlen)
		return (srclen + size);
	if (dstlen + i <= size)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
