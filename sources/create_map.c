/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:50 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:39 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_map *map)
{
	char	*line;

	line = get_next_line(map->fd);
	if (!line)
		error1(map, "Failed get next line");
	while (line != NULL)
	{
		map->array[map->row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!map->array[map->row])
		{
			free(line);
			error1(map, "Allocation failed");
		}
		while (line[map->i])
			map->array[map->row][map->j++] = line[map->i++];
		map->array[map->row][map->j] = '\0';
		map->row++;
		map->i = 0;
		map->j = 0;
		free(line);
		line = get_next_line(map->fd);
	}
	map->array[map->row] = NULL;
}

void	check_map_composition(t_map *map)
{
	map->i = 0;
	while (map->i < map->row)
	{
		map->j = 0;
		while (map->array[map->i][map->j] && map->array[map->i][map->j] != '\n')
		{
			if (map->array[map->i][map->j] == '0'
				|| map->array[map->i][map->j] == '1')
				;
			else if (map->array[map->i][map->j] == 'P')
			{
				map->py = map->i;
				map->px = map->j;
				map->p_count++;
			}
			else if (map->array[map->i][map->j] == 'E')
				map->e_count++;
			else if (map->array[map->i][map->j] == 'C')
				map->c_count++;
			else
				error1(map, "Wrong map composition");
			map->j++;
		}
		map->i++;
	}
}

void	check_shape(t_map *map)
{
	map->i = 0;
	while (map->i + 1 < map->row)
	{
		if (ft_strlen_upgrade(map->array[map->i])
			!= ft_strlen_upgrade(map->array[map->i + 1]))
			error1(map, "Map is not a rectangle");
		map->i++;
	}
	map->column = ft_strlen_upgrade(map->array[map->i]);
}

void	check_walls(t_map *map)
{
	map->j = 0;
	while (map->j && map->j != '\n')
	{
		if (map->array[0][map->j] != '1')
			error1(map, "Map is not surrounded by walls");
		if (map->array[map->row - 1][map->j] != '1')
			error1(map, "Map is not surrounded by walls");
		map->j++;
	}
	map->i = 0;
	while (map->i < map->row)
	{
		if (map->array[map->i][0] != '1')
			error1(map, "Map is not surrounded by walls");
		if (map->array[map->i][map->column - 1] != '1')
			error1(map, "Map is not surrounded by walls");
		map->i++;
	}
}

void	create_map(t_map *map)
{
	fill_map(map);
	check_map_composition(map);
	if (map->p_count != 1 || map->e_count != 1
		|| map->c_count < 1)
		error1(map, "Wrong map composition");
	check_shape(map);
	check_walls(map);
	check_path(map);
	close(map->fd);
}
