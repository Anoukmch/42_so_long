/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:56:21 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:27 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	size_map_row(char *mapfile, t_map *map)
{
	char	*line;
	int		size_row;
	int		fd;

	size_row = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		error1(map, "Failed get next line or map empty");
	while (line != NULL)
	{
		size_row++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (size_row);
}

t_map	*initialize(char *mapfile)
{
	t_map	*map;
	int		size_row;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error1(NULL, "Allocation failed");
	map->row = 0;
	size_row = size_map_row(mapfile, map);
	map->array = ft_calloc(size_row + 1, sizeof(char *));
	if (!map->array || size_row < 3)
		error1(map, "Allocation failed or lines number too low");
	map->fd = open(mapfile, O_RDONLY);
	if (map->fd < 0)
		error1(map, "Open failed");
	map->column = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->i = 0;
	map->j = 0;
	map->px = 0;
	map->py = 0;
	map->move_count = 0;
	return (map);
}
