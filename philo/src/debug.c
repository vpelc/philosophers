/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:58 by vpelc             #+#    #+#             */
/*   Updated: 2024/10/26 19:05:40 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	print_philo(t_life life)
{
	int	i;

	i = 0;
	while (i < life.nbr_philo)
	{
		printf("I am philo %d\n", life.philo_arr[i].id);
		i++;
	}
	return (0);
}
