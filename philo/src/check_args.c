/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:21:32 by vpelc             #+#    #+#             */
/*   Updated: 2024/10/26 18:53:59 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5)
		send_error("Not enough arguments\n");
	if (argc > 6)
		send_error("Too much arguments\n");
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				send_error("Arguments contains non digit char\n");
			j++;
		}
		i++;
	}
}
