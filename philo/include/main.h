/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:01:33 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/21 19:36:24 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				meals;
	int				sleeps;
	int				death_status;
	unsigned long	lastmeal_time;
	pthread_t		thread;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*next_fork;
	struct s_life	*life;
}					t_philo;

typedef struct s_life
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_meals;
	int				dead;
	unsigned long	prog_start_time;
	pthread_t		monitor;
	pthread_mutex_t	print;
	t_philo			*philo_arr;
}					t_life;

/*			SRC				*/
void				init_life(int argc, char *argv[], t_life *life);
void				check_args(int argc, char *argv[]);

int					birth(t_life *life);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);

size_t				ft_get_time_ms(void);
void				ft_usleep(size_t time);

void				send_error(char *err);

/*			DEBUG			*/
int					print_philo(t_life life);

#endif