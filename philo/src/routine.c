/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:07:40 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/21 19:41:47 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	*routine(void *philosopher)
{
	t_philo	*philo;
	
	philo = (t_philo *)philosopher;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->life->dead)
	{
		eating(philo);
		sleeping(philo);
	}
	return (philosopher);
}

void	*monitoring(void *story)
{
	t_life	*life;
	int		i;

	life = (t_life *)story;
	i = -1;
	while (1)
	{
		if (life->philo_arr[i].death_status != 0)
		{
			life->dead = 1;
			return (NULL);
		}
	}
	return (NULL);
}

int	birth(t_life *life)
{
	int	i;

	i = -1;
	life->prog_start_time = ft_get_time_ms();
	if (pthread_create(&life->monitor, NULL, monitoring, &(life)) != 0)
			return (i);
	while (++i < life->nbr_philo)
	{
		if (pthread_create(&life->philo_arr[i].thread, NULL, routine, &(life->philo_arr[i])) != 0)
			return (i);
	}
	i = -1;
	while (++i < life->nbr_philo)
	{
		if (pthread_join(life->philo_arr[i].thread, NULL) != 0)
			return (i);
	}
	if (pthread_join(life->monitor, NULL) != 0)
			return (i);
	return (0);
}

void	mutex_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	if (!philo->life->dead)
	{
		printf("%-12zu", (ft_get_time_ms() - philo->life->prog_start_time));
		printf("%-4d", philo->id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(philo->life->print));
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->own_fork));
	mutex_print("has taken a fork\n", philo);
	pthread_mutex_lock((philo->next_fork));
	mutex_print("has taken a fork\n", philo);
	mutex_print("is eating\n", philo);
	ft_usleep(philo->life->time_to_eat);
	pthread_mutex_unlock(&(philo->own_fork));
	pthread_mutex_unlock((philo->next_fork));
	
}

void	sleeping(t_philo *philo)
{
	mutex_print("is sleeping\n", philo);
	ft_usleep(philo->life->time_to_sleep);
	mutex_print("is thinking\n", philo);
}
