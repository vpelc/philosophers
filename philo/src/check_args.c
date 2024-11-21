/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:21:32 by vpelc             #+#    #+#             */
/*   Updated: 2024/11/20 14:08:02 by vpelc            ###   ########.fr       */
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
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				send_error("\n. Arguments contains non digit char\n\n");
			j++;
		}
	}
}
