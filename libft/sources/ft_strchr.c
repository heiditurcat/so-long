/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:38:14 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:06 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c % 128)
		return ((char *)&s[i]);
	return (0);
}

/*char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c % 128)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c % 128)
		return ((char *)&s[i]);
	else
		return (NULL);
}*/
