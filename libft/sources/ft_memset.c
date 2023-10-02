/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:38:09 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:26:42 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*chars;
	size_t	i;

	chars = s;
	i = 0;
	while (i < n)
	{
		chars[i] = c;
		i++;
	}
	return (s);
}
