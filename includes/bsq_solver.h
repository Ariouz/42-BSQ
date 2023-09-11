/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:25:12 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 14:25:13 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_structures.h"

int	ft_min(int a, int b, int c);

int	ft_max(int a, int b);

t_biggest	get_biggest(int **map, int maxRow, int maxCol);
