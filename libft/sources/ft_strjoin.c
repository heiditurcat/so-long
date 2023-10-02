/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturcat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:36:40 by hturcat           #+#    #+#             */
/*   Updated: 2023/09/07 17:27:15 by hturcat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*catstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	catstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!catstr)
		return (NULL);
	while (s1[i])
		catstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		catstr[j++] = s2[i++];
	catstr[j] = '\0';
	free (s1);
	return (catstr);
}

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	int		strlen;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	catstr = malloc (sizeof(char) * (strlen + 1));
	if (!catstr)
		return (NULL);
	while (s1[i])
	{	
		catstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		catstr[i++] = s2[j++];
	}
	catstr[i] = '\0';
	return (catstr);
}*/
