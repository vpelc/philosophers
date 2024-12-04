/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:01:01 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/16 18:24:16 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnbr(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static	char	*ft_putstr(long n, char *str, size_t size)
{
	str[size] = '\0';
	size--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[size] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	str[size] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	size = ft_strnbr(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	ft_putstr(nbr, str, size);
	return (str);
}
