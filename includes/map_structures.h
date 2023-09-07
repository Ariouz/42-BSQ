/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:39:14 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/07 10:42:39 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_STRUCTURES_H
# define MAP_STRUCTURES_H

typedef struct s_map 
{
	char	*filename;
	int		x;
	int		y;
}	t_map;

typedef struct s_rect
{
	char	*map_filename;
	int		x;
	int		y;
	int		size;
}	t_rect;

#endif
