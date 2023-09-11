/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 16:53:18 by vicalvez         ###   ########.fr       */
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
	t_map	*maps;

	if (argc <= 1)
	{
		map_error();
		return (1);
	}

	maps = get_maps(argv, argc);
	is_map_error(maps);
	printf("%s\n", maps[0].content[0]);
	close_maps(maps);

	//t_map_chars	map_chars = maps[0].map_chars;

	t_biggest biggest;

	maps[0].map_chars.empty = '.';
	maps[0].map_chars.obstacle = 'o';

	printf("char empty: %c, char obstacle: %c\n", maps[0].map_chars.empty, maps[0].map_chars.obstacle);
	printf("Taille map x %d, y %d\n", maps[0].x, maps[0].y);
        biggest = get_biggest(mtoi(maps[0], maps[0].y, maps[0].x), maps[0].y, maps[0].x);
        printf("\nLe plus grand est en %d,%d et fait %d\n", biggest.row, biggest.col, biggest.value);

	int	i = 0;
	int	j = 0;
	int	**imap = mtoi(maps[0], maps[0].y, maps[0].x);
	while (j < maps[0].y)
	{
		while (i < maps[0].x)
		{
			if (j + biggest.value - 1 >= biggest.row  && j + biggest.value<= biggest.row + biggest.value
					&& i + biggest.value - 1 >= biggest.col && i + biggest.value <= biggest.col + biggest.value)
			{
				printf(".");
			}
			else
				printf("%d", imap[j][i]);
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}

	free(maps);
	return (0);
}
