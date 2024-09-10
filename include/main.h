/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:01:33 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/10 18:12:46 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				meals;
	int				sleeps;
	pthread_t		thread;
	pthread_mutex_t	own_fork;
	pthread_mutex_t	*next_fork;
	

}	t_philo;


#endif