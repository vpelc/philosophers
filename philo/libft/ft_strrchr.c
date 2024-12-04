/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:40:48 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/26 15:27:00 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	char	*str;

	str = (char *)s;
	n = ft_strlen(str);
	while (n > 0 && str[n] != (unsigned char)c)
		n--;
	if (n == 0 && str[n] != (unsigned char)c)
		return (0);
	return (str + n);
}
