/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:43:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/08 09:08:54 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include "../includes/files.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void    map_error()
{
        ft_putstr("map_error\n");
}

t_map	*get_maps(char **filenames, int fc)
{
	t_map	*maps;
	t_map	map;
	int	i;

	i = 1;
	maps =  malloc(sizeof(t_map) * (fc + 1));
	if (!maps)
	{
		map_error();
		exit(2);
	}
	while (i < fc)
 	{
		printf("%s\n", filenames[i]);
		map.fd = open(filenames[i], O_RDONLY);
		// TODO INIT MAP X,Y
		maps[i-1] = map;
		i++;
	}
	maps[i-1].fd = -2;
	return (maps);
}

void	is_map_error(t_map *maps)
{
	int	i;

	i = 0;
	while(maps[i].fd != -2)
	{
		printf("%d\n", maps[i].fd);
		if (maps[i].fd == -1)
		{
			map_error();
			exit(2);
		}
		i++;
	}
	printf("test");
}
