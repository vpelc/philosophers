/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:07:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/26 15:26:56 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*hay;
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	hay = (char *)haystack;
	if (!needle[i])
		return (&hay[i]);
	while (i < n && hay[i])
	{
		j = 0;
		tmp = i;
		while (hay[i] == needle[j] && i < n)
		{
			if (needle[j + 1] == '\0')
				return (&hay[i - j]);
			j++;
			i++;
		}
		i = tmp;
		i++;
	}
	return (0);
}
