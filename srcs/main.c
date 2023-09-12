/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 15:55:30 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include "../includes/map_structures.h"
#include <stdio.h>
#include "../includes/bsq_solver.h"
#include "../includes/result_printer.h"
#include <stdlib.h>

void	go_free(t_map *maps, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < count)
	{
		while(j < maps[i].y)
		{
			free(maps[i].content[j]);
			j++;
		}
		j = 0;
		free(maps[i].content);
		i++;
	}
	free(maps);
}

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
	count = 0;
	while (count != argc - 1)
	{
		aff_result(count, maps);
		count++;

	}
	go_free(maps, count);
	return (0);
}
