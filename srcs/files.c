/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:05:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/08 09:21:12 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include <stdio.h>

void	close_maps(t_map *maps)
{
	int	i;

	i = 0;
	while (maps[i].fd != -2)
	{
		close(maps[i].fd);
		i++;
	}
}

char	**read_file(t_map *maps, int fc)
{
	char **maps_stocks;
	char	*buffer;
	int	i;
	
	printf("test");
	maps_stocks  = malloc((fc + 1) * sizeof(char *));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!maps_stocks)
		return (NULL);
	i = 0;
	while (maps[i].fd != -2)
	{
		read(maps[i].fd, buffer, BUFFER_SIZE);
		maps_stocks[i] = buffer;
		printf("%s\n", buffer);
		i++;
	}
	return (maps_stocks);
}
