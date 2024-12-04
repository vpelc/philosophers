/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:11:17 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/26 15:26:35 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	size_d;
	size_t	i;

	if (!dest && n == 0)
		return (ft_strlen(src));
	size_d = ft_strlen(dest);
	i = 0;
	if (n <= size_d)
		return (ft_strlen(src) + n);
	while ((i < n - size_d - 1) && src[i] != '\0')
	{
		dest[size_d + i] = src[i];
		i++;
	}
	dest[size_d + i] = '\0';
	return (ft_strlen(src) + size_d);
}
