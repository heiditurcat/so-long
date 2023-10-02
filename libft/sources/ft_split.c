/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:31:06 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:04 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	start;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		word_count++;
	}
	return (word_count);
}

static void	**ft_free(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
	{
		free (strstr[i]);
		strstr[i] = NULL;
		i++;
	}
	free (strstr);
	return (NULL);
}

char	**ft_write_word(char **strstr, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		start = i;
		while (s[i] && (s[i] != c))
			i++;
		if (i > start)
		{
			strstr[j] = ft_substr(s, start, i - start);
			j++;
			if (!strstr[j - 1])
				return (*ft_free(strstr));
		}
	}
	return (strstr);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	int		i;
	int		start;
	int		j;
	char	**strstr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	word_count = ft_wordcount(s, c);
	strstr = malloc (sizeof(char *) * (word_count + 1));
	if (!strstr)
		return (NULL);
	strstr[word_count] = NULL;
	strstr = ft_write_word(strstr, s, c);
	return (strstr);
}
