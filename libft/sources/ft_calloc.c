/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:16:16 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:14:54 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*newmem;

	if ((size > 0) && (nmemb > ULLONG_MAX / size))
		return (NULL);
	newmem = malloc(nmemb * size);
	if (!newmem)
		return (NULL);
	ft_bzero(newmem, nmemb * size);
	return (newmem);
}
