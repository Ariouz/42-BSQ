/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:58:36 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/07 14:30:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utils.h"
#include "../includes/files.h"
#include "../includes/ft_functions.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_map	**maps;

	if (argc <= 1)
	{
		map_error();
		return (1);
	}
	
	maps = get_maps(argv, argc);
	if (is_map_error(maps))
		return (2);
	
	free(maps);
	return (0);
}
