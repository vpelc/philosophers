/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:10:33 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/27 17:32:01 by vpelc            ###   ########.fr       */
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
		usleep(10);
}

void	mutex_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	pthread_mutex_lock(&philo->life->death_check);
	pthread_mutex_lock(&philo->life->meal_check);
	if (!philo->life->dead && !philo->life->end)
	{
		printf("\033[1;35m%-10zu\033[0m", (ft_get_time_ms() - philo->life->prog_start_time));
		printf("\033[1;33m%-4d\033[0m", philo->id);
		printf("%-30s", str);
		if (philo->life->nbr_meals >= 0)
			printf("\033[1;35m%i\033[0m", philo->meals);
		printf("\n\n");
	}
	pthread_mutex_unlock(&philo->life->death_check);
	pthread_mutex_unlock(&philo->life->meal_check);
	pthread_mutex_unlock(&(philo->life->print));
}

void	mutex_print_f(char *str, t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	printf("\033[1;35m%-10zu\033[0m", (ft_get_time_ms() - philo->life->prog_start_time));
	printf("\033[1;33m%-4d\033[0m", philo->id);
	printf("%-30s", str);
	printf("\n\n");
	pthread_mutex_unlock(&(philo->life->print));
}
