/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:40 by vpelc             #+#    #+#             */
/*   Updated: 2024/10/30 18:06:55 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	routine(void)
{
	printf("I'm ok\n");
}

int	philo_loop(t_life life)
{
	int	i;

	i = 0;
	while (i < life.nbr_philo)
	{
		if (pthread_create(&life.philo_arr[i], NULL, routine, NULL) != 0)
			return (i);
		i++;
	}
	i = 0;
	while (i < life.nbr_philo)
	{
		if (pthread_join(&life.philo_arr[i], NULL) != 0)
			return (i);
		i++;
	}
	return (0);
}
