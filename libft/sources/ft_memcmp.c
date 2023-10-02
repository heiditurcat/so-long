/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:22:57 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:15:10 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	i = 0;
	ptrs1 = (unsigned char *) s1;
	ptrs2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (ptrs1[i] == ptrs2[i] && i + 1 < n)
		i++;
	return (ptrs1[i] - ptrs2 [i]);
}
