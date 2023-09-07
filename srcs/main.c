/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/07 11:55:36 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include <stdio.h>


int	main(void)
{
//	t_map	**maps;


	t_map	map;
	map = init_map("map.txt");
	if (map.fd == -1)
	{	ft_putstr("map error\n");
		return (1);
	}
	printf("map fd: %d\n", map.fd);

	
	/*char **filenames = {"map"};
	maps = get_maps(filenames, 1);
	free(maps);*/
	return (0);
}
