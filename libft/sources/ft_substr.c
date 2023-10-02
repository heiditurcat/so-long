/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:36:11 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:43 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	str_size;

	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start > str_size)
		return (ft_calloc (1, 1));
	else if (len >= str_size)
		str_size = str_size - start;
	else
		str_size = len;
	if (str_size < 0)
		str_size = 0;
	newstr = malloc(sizeof(char) * str_size + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s[start], str_size + 1);
	return (newstr);
}
