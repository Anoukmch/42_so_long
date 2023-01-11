/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:46:53 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:30 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **array, int y, int x)
{
	array[y][x] = '1';
	if (array[y][x + 1] != '1')
		flood_fill(array, y, x + 1);
	if (array[y][x - 1] != '1')
		flood_fill(array, y, x - 1);
	if (array[y + 1][x] != '1')
		flood_fill(array, y + 1, x);
	if (array[y - 1][x] != '1')
		flood_fill(array, y - 1, x);
}

char	**arraycopy(t_map *map)
{
	char	**copy;

	map->i = 0;
	copy = (char **)ft_calloc((map->row + 1), sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (map->i < map->row)
	{
		copy[map->i] = ft_strdup(map->array[map->i]);
		map->i++;
	}
	copy[map->row] = NULL;
	return (copy);
}

void	check_path(t_map *map)
{
	char	**copy;

	copy = arraycopy(map);
	flood_fill(copy, map->py, map->px);
	map->i = 0;
	while (map->i < map->row)
	{
		map->j = 0;
		while (copy[map->i][map->j] && copy[map->i][map->j] != '\n')
		{
			if (copy[map->i][map->j] == 'C' || copy[map->i][map->j] == 'E')
			{
				free_array(copy);
				error1(map, "No valid path");
			}
			map->j++;
		}
		map->i++;
	}
	free_array(copy);
}
