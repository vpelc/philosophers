/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:45:40 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/27 16:46:00 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int death(t_life *life)
{
	int i;

	i = -1;
	while (++i < life->nbr_philo)
	{
		if (pthread_mutex_destroy(&(life->philo_arr[i].left_fork)) != 0)
			return (i);
	}
	if (pthread_mutex_destroy(&(life->print)) != 0)
			return (i);
	if (pthread_mutex_destroy(&(life->death_check)) != 0)
			return (i);
	if (pthread_mutex_destroy(&(life->meal_check)) != 0)
			return (i);
	return (0);
	
}

int	rest(t_life *life)
{
	int i;

	i = -1;
	while (++i < life->nbr_philo)
	{
		if (pthread_join(life->philo_arr[i].thread, NULL) != 0)
			return (i);
	}

	return (0);
}

