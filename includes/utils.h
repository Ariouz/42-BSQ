/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:30:58 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/11 20:10:40 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_structures.h"

t_map	*get_maps(char **filenames, int fc);

int	is_map_error(t_map *maps);

void	map_error();

t_map_chars	check_card(t_map_chars card, char *str);

void	check_lines(t_map map);
