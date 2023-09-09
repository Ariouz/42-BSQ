/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:30:29 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/08 09:57:56 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_structures.h"

void	close_maps(t_map *maps);

//char	***read_file(t_map *maps, int nb_map);
char	**get_map_content(int fd);
