/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:10:33 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/21 19:33:56 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	send_error(char *err)
{
	write(2, "\n\033[1;31mError!\033[0m", 19);
	write(2, err, ft_strlen(err));
	exit(1);
}

size_t	ft_get_time_ms(void)
{
	struct timeval	t;	
	
	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(size_t time)
{
	size_t			start;

	start = ft_get_time_ms();
	while ((ft_get_time_ms() - start) < time)
		usleep(50);
}
