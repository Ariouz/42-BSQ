/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:05:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/07 11:41:03 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"

t_map	init_map(char *filename)
{
	int	fd;
	t_map	map;

	fd = open(filename, O_RDONLY);
	map.fd = fd;
	close(fd);
	return (map);
}
