/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:00:55 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/15 13:57:02 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	main(int argc, char *argv[])
{
	t_life	life;

	check_args(argc, argv);
	init_life(argc, argv, &life);
	//print_philo(life);
	return (0);
}
