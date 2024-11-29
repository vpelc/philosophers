/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:00:55 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/29 13:41:11 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	main(int argc, char *argv[])
{
	t_life	life;

	check_args(argc, argv);
	init_life(argc, argv, &life);
	birth(&life);
	monitoring(&life);
	rest(&life);
	death(&life);
	return (0);
}
