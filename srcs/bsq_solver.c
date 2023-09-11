/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:30:41 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 11:55:25 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map_structures.h"

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_biggest	get_biggest(int **map, int maxRow, int maxCol)
{
	int		row;
	int		col;
	int		max;
	t_biggest	biggest;

	row =  0;
	col = 0;
	max = 0;
	while (row < maxRow)
	{
		while(col < maxCol)
		{
			if (row == 0 || col == 0)
				max = ft_max(max, map[row][col])
			else if (map[row][col] == 1)
			{
				map[row][col] = ft_min(map[row-1][col], map[row][col - 1], map[row - 1][col - 1]) + 1;
				max = ft_max(map[row][col]);
				biggest.row = row;
				biggest.col = col;
			}
			col++;
		}
		col = 0;
		row++;
	}
	biggest.value = max;
}
