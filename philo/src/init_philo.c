/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:35:23 by vpelc             #+#    #+#             */
/*   Updated: 2024/12/04 13:01:10 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_philo	*init_philo(t_life *life)
{
	int		i;
	t_philo	*philo_arr;

	philo_arr = malloc(sizeof(t_philo) * (life->nbr_philo + 1));
	i = -1;
	while (life->nbr_philo > ++i)
	{
		philo_arr[i].id = i + 1;
		philo_arr[i].meals = 0;
		philo_arr[i].sleeps = 0;
		pthread_mutex_init(&philo_arr[i].left_fork, NULL);
		philo_arr[i].life = life;
		philo_arr[i].lastmeal_time = ft_get_time_ms();
	}
	i = -1;
	while (life->nbr_philo > ++i)
	{
		if (i != 0)
			philo_arr[i].right_fork = &philo_arr[i - 1].left_fork;
		else
			philo_arr[i].right_fork = &philo_arr[life->nbr_philo - 1].left_fork;
	}
	return (philo_arr);
}

void	init_life(int argc, char *argv[], t_life *life)
{
	life->nbr_philo = ft_atoi(argv[1]);
	life->time_to_die = ft_atoi(argv[2]);
	life->time_to_eat = ft_atoi(argv[3]);
	life->time_to_sleep = ft_atoi(argv[4]);
	life->nbr_meals = -1;
	if (argc == 6)
		life->nbr_meals = ft_atoi(argv[5]);
	check_args_2(life);
	life->philo_arr = init_philo(life);
	life->dead = 0;
	life->end = 0;
	life->enough_meals = 0;
	pthread_mutex_init(&life->print, NULL);
	pthread_mutex_init(&life->death_check, NULL);
	pthread_mutex_init(&life->meal_check, NULL);
}
