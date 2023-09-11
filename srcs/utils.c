/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:43:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 20:39:34 by thoribal         ###   ########.fr       */
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
	j = 2;
	while(maps[i].fd != -2)
	{
		if (maps[i].fd == -1)
		{
			map_error();
			exit(2);
		}
		while(maps[i].content[j])
		{
			if(ft_strlen(maps[i].content[1]) == ft_strlen(maps[i].content[j - 1]))
				j++;
			else
			{
				map_error();
				exit(3);
			}
		}
	j = 2;
	i++;

	}
}

t_map_chars	check_card(t_map_chars	card, char *str)
{
	int	len;

	len = ft_strlen(str) - 3;
	if (str[len] == str[len + 1] || str[len] == str[len + 2] || str[len + 1] == str[len + 2])
	{
		printf("Erreur a mettre au propre cards egaux");
		exit(5);
	}
	card.empty = str[len];
	card.obstacle = str[len + 1];
	card.full = str[len + 2];
	return (card);
}

void	check_lines(t_map map)
{
	int	i;
	int	o;

	i = 1;
	o = 1;
	while(i != ft_atoi(map.content[0]))
	{
		if (!(map.content[i][o] == map.map_chars.empty 
					|| map.content[i][o] == map.map_chars.obstacle 
					|| map.content[i][o] == '\n'
				       	|| map.content[i][o] == '\0'))
		{
			printf("Erreur char pas desire !");
			exit(5);
		}
		if (map.content[i][o] == '\0')
		{
			
			i++;
			o = -1;
		}
		o++;
	}
}
