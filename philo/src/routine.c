/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:40 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/27 18:06:21 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	*routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	// if (philo->id % 2 == 0)
	// 	usleep(1000);
	while (!philo->life->dead && !philo->life->end)
	{
		pthread_mutex_lock(&philo->life->death_check);
		pthread_mutex_lock(&philo->life->meal_check);
		pthread_mutex_unlock(&philo->life->death_check);
		pthread_mutex_unlock(&philo->life->meal_check);
		eating(philo);
		mutex_print("\033[1;36mis sleeping\033[0m", philo);
		ft_usleep(philo->life->time_to_sleep);
		mutex_print("\033[1;34mis thinking\033[0m", philo);
	}
	return (philosopher);
}



int	birth(t_life *life)
{
	int	i;

	i = -1;
	life->prog_start_time = ft_get_time_ms();
	while (++i < life->nbr_philo)
	{
		life->philo_arr[i].lastmeal_time = life->prog_start_time;
		if (pthread_create(&life->philo_arr[i].thread, NULL, routine, &(life->philo_arr[i])) != 0)
			return (i);
	}

	return (0);
}

void	taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->left_fork));
		mutex_print("\033[1;30mhas taken a fork\033[0m", philo);
		pthread_mutex_lock((philo->right_fork));
		mutex_print("\033[1;30mhas taken a fork\033[0m", philo);
	}
	else
	{
		pthread_mutex_lock((philo->right_fork));
		mutex_print("\033[1;30mhas taken a fork\033[0m", philo);
		pthread_mutex_lock(&(philo->left_fork));
		mutex_print("\033[1;30mhas taken a fork\033[0m", philo);
	}
}

void	eating(t_philo *philo)
{
	if (philo->life->nbr_philo == 1)
	{
		pthread_mutex_lock(&(philo->left_fork));
		mutex_print("\033[1;30mhas taken a fork\033[0m", philo);
		ft_usleep(philo->life->time_to_die);
		return ;
	}
	taking_forks(philo);
	mutex_print("\033[1;32mis eating\033[0m", philo);
	pthread_mutex_lock(&philo->life->meal_check);
	philo->meals++;
	if (philo->meals == philo->life->nbr_meals)
		philo->life->enough_meals++;
	pthread_mutex_unlock(&philo->life->meal_check);
	pthread_mutex_lock(&philo->life->death_check);
	philo->lastmeal_time = ft_get_time_ms();
	pthread_mutex_unlock(&philo->life->death_check);
	ft_usleep(philo->life->time_to_eat);
	pthread_mutex_unlock(&(philo->left_fork));
	pthread_mutex_unlock((philo->right_fork));
	
}
