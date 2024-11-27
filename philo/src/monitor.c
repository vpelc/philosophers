/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:10:11 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/27 17:30:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	monitoring(t_life *life)
{
	int		i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&life->death_check);
		if ((ft_get_time_ms() - life->philo_arr[i].lastmeal_time)
			>= (unsigned long)life->time_to_die)
		{
			mutex_print_f("\033[1;31mis dead\033[0m",&life->philo_arr[i]);
			life->dead = 1;
			pthread_mutex_unlock(&life->death_check);
			return (1);
		}
		pthread_mutex_unlock(&life->death_check);
		pthread_mutex_lock(&life->meal_check);
		if (life->enough_meals == life->nbr_philo)
		{
			life->end = 1;
			pthread_mutex_unlock(&life->meal_check);
			return (1);
		}
		pthread_mutex_unlock(&life->meal_check);
		i = (i + 1) % life->nbr_philo;
	}
	return (0);
}
