/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:14:32 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/17 17:00:52 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\t'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static	int	ft_isnegative(char str)
{
	if (str == '+')
		return (1);
	if (str == '-')
		return (-1);
	return (0);
}

static	int	check_longmax(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (j > 19)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;	
	int	n;

	n = 1;
	r = 0;
	i = ft_isspace(str);
	if (ft_isnegative(str[i]) != 0)
	{
		n *= ft_isnegative(str[i]);
		i++;
	}
	if (check_longmax(str, i))
	{
		if (n == -1)
			return (0);
		return (-1);
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10;
		r = r + (str[i] - 48);
		i++;
	}
	return (r * n);
}
