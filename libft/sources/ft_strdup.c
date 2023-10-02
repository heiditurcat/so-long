/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:29 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:11 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;
	char	*newsrc;

	i = 0;
	newsrc = (char *)s;
	len = ft_strlen(s) + 1;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	while (newsrc[i])
	{
		dest[i] = newsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;
	char	*newsrc;

	i = 0;
	newsrc = (char *)s;
	len = ft_strlen(s) + 1;
	dest = malloc(len * sizeof(char));
	if (!dest)
		return (NULL);
	while (newsrc[i])
	{
		dest[i] = newsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}*/
