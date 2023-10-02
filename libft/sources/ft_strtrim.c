/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:34:56 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:35 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

static int	ft_end(char const *s1, char const *set, int len)
{
	int	i;
	int	j;

	i = len - 1;
	j = 0;
	while (set[j] && i >= 0)
	{
		while (s1[i] == set[j] && (i >= 0))
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

static char	*ft_relou(void)
{
	char	*s1trim;

	s1trim = malloc (sizeof(char) * 1);
	if (!s1trim)
		return (NULL);
	s1trim[0] = '\0';
	return (s1trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1trim;
	int		start;
	int		end;
	int		k;

	if (!s1)
		return (0);
	k = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set, ft_strlen(s1));
	if (end - start < 0)
	{
		s1trim = ft_relou();
		return (s1trim);
	}
	else
		s1trim = malloc (sizeof(char) * (end - start + 2));
	if (!s1trim)
		return (NULL);
	while (start <= end)
		s1trim[k++] = s1[start++];
	s1trim[k] = '\0';
	return (s1trim);
}
