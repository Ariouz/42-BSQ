/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:24:54 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 16:20:25 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map_structures.h"
#include "../includes/ft_functions.h"
#include "../includes/mtoi.h"
#include "../includes/utils.h"
#include "../includes/bsq_solver.h"
#include <stdio.h>

int	check_errors(t_map map)
{
	if (is_map_error(map) || check_lines(map)
			|| map.map_chars.empty == 0)
		return (1);
	return (0);
}

void	aff_result(int count, t_map *maps)
{
	t_biggest biggest;
	int	**_mtoi;
	int	i = 0;
	int	j = 0;

	maps[count].map_chars = check_card(maps[count].map_chars, maps[count].content[0]);
	_mtoi = mtoi(maps[count], maps[count].y, maps[count].x);
	if (check_errors(maps[count]))
	{
		map_error();
		//free(_mtoi);
		return ;
	}
	biggest = get_biggest(_mtoi, maps[count].y, maps[count].x);
	while (j < maps[count].y)
	{
		while (i < maps[count].x)
		{
			if (j + biggest.value - 1 >= biggest.row  && j + biggest.value<= biggest.row + biggest.value
					&& i + biggest.value - 1 >= biggest.col && i + biggest.value <= biggest.col + biggest.value)
				ft_putchar(maps[count].map_chars.full);
			else
			{
				if (_mtoi[j][i] == 0)
					ft_putchar(maps[count].map_chars.obstacle);
				else if (_mtoi[j][i] > 0)
					ft_putchar(maps[count].map_chars.empty);
			}
			i++;
		}
		ft_putchar('\n');
		i = 0;
		free(_mtoi[j]);
		j++;
	}
	free(_mtoi);
}
