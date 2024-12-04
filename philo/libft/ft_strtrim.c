/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:48:57 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/26 15:27:08 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && ft_check_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_check_set(s1[j - 1], set))
		j--;
	cpy = malloc(sizeof(char) * ((j - i) + 1));
	if (!cpy)
		return (0);
	k = 0;
	while (i + k < j)
	{
		cpy[k] = s1[i + k];
		k++;
	}
	cpy[k] = '\0';
	return (cpy);
}
