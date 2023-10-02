/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:36:22 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:25 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*news;
	unsigned int	i;
	unsigned int	len_s;

	if (!s || !f)
		return (0);
	i = 0;
	len_s = ft_strlen(s);
	news = malloc(sizeof(char) * (len_s + 1));
	if (news == NULL)
		return (NULL);
	while (i < len_s)
	{
		news[i] = f(i, s[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}
