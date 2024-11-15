/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:22:48 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/15 15:07:34 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	send_error(char *err)
{
	write(2, "\n\033[1;31mError!\033[0m", 19);
	write(2, err, ft_strlen(err));
	exit(1);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time_in_ms();
	while ((get_current_time_in_ms() - start) < time)
		usleep(500);
}
