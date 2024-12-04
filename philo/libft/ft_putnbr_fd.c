/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:46:15 by vpelc             #+#    #+#             */
/*   Updated: 2024/04/26 15:26:04 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', fd);
	}
	if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(l % 10 + 48, fd);
	}
	if (l < 10)
		ft_putchar_fd(l % 10 + 48, fd);
}
