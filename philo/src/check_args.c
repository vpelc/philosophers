/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:21:32 by vpelc             #+#    #+#             */
/*   Updated: 2024/12/04 14:13:23 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5)
		send_error("\n. Not enough arguments\n\n");
	if (argc > 6)
		send_error("\n. Too much arguments\n\n");
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			send_error("\n. Numbers need to be within INT limits\n\n");
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j]))
			&& (argv[i][j] != '+' && argv[i][j] != '-'))
				send_error("\n. Arguments contains non digit char\n\n");
			j++;
		}
	}
}

void	check_args_2(t_life *life)
{
	if (life->nbr_philo < 1)
		send_error("\n. Need at least one philosopher\n\n");
	if (life->nbr_philo > 200)
		send_error("\n. Too many philosophers\n\n");
	if (life->time_to_die < 60 || life->time_to_sleep < 60
		|| life->time_to_eat < 60)
		send_error("\n. Time too small\n\n");
}
