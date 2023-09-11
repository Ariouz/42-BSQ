/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:05:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 14:09:45 by thoribal         ###   ########.fr       */
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

char	**get_map_content(int fd)
{
	char	**content;
	char	*buffer;
	int	i;
	int	j;
	int	buf;

	buffer = malloc(BUFFER_SIZE  * sizeof(char));
	content = malloc(BUFFER_SIZE * sizeof(char *));
	i = 0;
	j = 0;
	content[j] = malloc(BUFFER_SIZE * sizeof(char));
	while ((buf = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			content[++j] = malloc(BUFFER_SIZE * sizeof(char));
		content[j][i] = buffer[0];
		i++;
	}
	if (j - 1 != ft_atoi(content[0]))
		printf("**Erreur Map size add fonc !**");
	return content;
}

/*char	**read_file(t_map *maps, int fc)
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
		//printf("%s\n", buffer);
		i++;
	}
	return (maps_stocks);
}*/
