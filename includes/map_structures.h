/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:39:14 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 11:54:53 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_STRUCTURES_H
# define MAP_STRUCTURES_H
# define BUFFER_SIZE 100000000

typedef struct s_map 
{
	int	fd;
	int	x;
	int	y;
	char	**content;
	int	**imap;
}	t_map;

typedef struct s_rect
{
	int	map_fd;
	int	x;
	int	y;
	int	size;
}	t_rect;

typedef struct s_biggest
{
	int	row;
	int	col;
	int	value;
}	t_biggest;



#endif
