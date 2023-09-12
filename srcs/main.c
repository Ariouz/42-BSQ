/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 12:32:21 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include "../includes/map_structures.h"
#include <stdio.h>
#include "../includes/mtoi.h"
#include "../includes/bsq_solver.h"


int	main(int argc, char **argv)
{
	int	count;
	t_map	*maps;

	if (argc <= 1)
	{
		// pas map erreur mais recuperer map en entre
		// todo read(0);
		return (1);
	}
	maps = get_maps(argv, argc);
	close_maps(maps);
	t_biggest biggest;
	count = 0;
	while (count != argc - 1)
	{

		if (is_map_error(maps[count]))
		{
			continue ;
		}
		maps[count].map_chars = check_card(maps[count].map_chars, maps[count].content[0]);
		check_lines(maps[count]);
        	int     **_mtoi = mtoi(maps[count], maps[count].y, maps[count].x);
		biggest = get_biggest(_mtoi, maps[count].y, maps[count].x);
		int	i = 0;
		int	j = 0;
		while (j < maps[count].y)
		{
			while (i < maps[count].x)
			{
				if (j + biggest.value - 1 >= biggest.row  && j + biggest.value<= biggest.row + biggest.value
                                        && i + biggest.value - 1 >= biggest.col && i + biggest.value <= biggest.col + biggest.value)
					ft_putchar(maps[count].map_chars.full);
				else
				{
					if (_mtoi[j][i] == 0)
						ft_putchar(maps[count].map_chars.obstacle);
					else if (_mtoi[j][i] > 0)
						ft_putchar(maps[count].map_chars.empty);
				}

				i++;
			}
			ft_putchar('\n');
			i = 0;
			free(_mtoi[j]);
			free(maps[count].content[j]);
			j++;
		}
		free(maps[count].content);
		free(_mtoi);
		count++;
	}
	free(maps);
	return (0);
}
