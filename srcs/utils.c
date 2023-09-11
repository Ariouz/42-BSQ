/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:43:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 14:57:56 by vicalvez         ###   ########.fr       */
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
		map.fd = open(filenames[i], O_RDONLY);
		set_map_content(map.fd, &map);
		maps[i-1] = map;
		i++;
	}
	maps[i-1].fd = -2;
	return (maps);
}

void	is_map_error(t_map *maps)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(maps[i].fd != -2)
	{
		if (maps[i].fd == -1)
		{
			map_error();
			exit(2);
		}
		/*while(maps[i].content[j])
		{
			if(ft_strlen(maps[i].content[1]) == ft_strlen(maps[i].content[j]))
				j++;
			else
			{
				map_error();
				exit(3);
			}
		}*/
	j = 1;
	i++;
	}
}
