/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:05:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/07 14:52:44 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"

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
