/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:35:23 by vpelc             #+#    #+#             */
/*   Updated: 2024/10/26 19:19:39 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_philo	*init_philo(t_life *life)
{
	int		i;
	t_philo	*philo_arr;

	philo_arr = malloc(sizeof(t_philo) * (life->nbr_philo + 1));
	i = 0;
	while (life->nbr_philo > i)
	{
		philo_arr[i].id = i;
		philo_arr[i].meals = 0;
		philo_arr[i].sleeps = 0;
		pthread_mutex_init(&philo_arr[i].own_fork, NULL);
		i++;
	}
	i = 0;
	while (life->nbr_philo > i)
	{
		if (life->nbr_philo - 1 > i && i % 2 == 0)
			philo_arr[i].next_fork = &philo_arr[i + 1].own_fork;
		else if (life->nbr_philo - 1 > i && i % 2 != 0)
			philo_arr[i].next_fork = &philo_arr[i - 1].own_fork;
		else
			philo_arr[i].next_fork = &philo_arr[0].own_fork;
		i++;
	}
	return (philo_arr);
}

void	init_life(int argc, char *argv[], t_life *life)
{
	life->nbr_philo = ft_atoi(argv[1]);
	life->time_to_die = ft_atoi(argv[2]);
	life->time_to_eat = ft_atoi(argv[3]);
	life->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		life->nbr_meals = ft_atoi(argv[5]);
	life->philo_arr = init_philo(life);
}
