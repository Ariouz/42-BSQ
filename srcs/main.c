/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/08 09:19:44 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include "../includes/map_structures.h"
#include <stdio.h>


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
	printf("test");
	read_file(maps, argc);
	close_maps(maps);	
	free(maps);
	return (0);
}
