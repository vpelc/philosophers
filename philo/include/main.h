/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:01:33 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/27 17:32:11 by vpelc            ###   ########.fr       */
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
	unsigned long	lastmeal_time;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
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
	int				end;
	int				enough_meals;
	unsigned long	prog_start_time;
	pthread_t		monitor;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	death_check;
	pthread_mutex_t	print;
	t_philo			*philo_arr;
}					t_life;

/*			SRC				*/
void				init_life(int argc, char *argv[], t_life *life);
void				check_args(int argc, char *argv[]);
void				check_args_2(t_life *life);

/* thread routines */
void				*routine(void *philosopher);
int					monitoring(t_life *life);

/* philo actions */
int					birth(t_life *life);
int					rest(t_life *life);
int					death(t_life *life);
void				eating(t_philo *philo);

/* time */
size_t				ft_get_time_ms(void);
void				ft_usleep(size_t time);

void				mutex_print(char *str, t_philo *philo);
void				mutex_print_f(char *str, t_philo *philo);
void				send_error(char *err);

/*			DEBUG			*/
int					print_philo(t_life life);

#endif