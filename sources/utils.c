/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:59:34 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:33 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen_upgrade(const char *s)
{
	size_t	c;
	char	*str;

	c = 0;
	str = (char *)s;
	while (str[c] && str[c] != '\n')
		c++;
	return (c);
}

void	error1(t_map *map, char *string)
{
	if (map)
	{
		free_array(map->array);
		free(map);
	}
	ft_printf("%s\n", string);
	exit(1);
}

void	error2(t_map *map, t_texture *txtr, t_image	*img, char *string)
{
	if (txtr)
		free(txtr);
	if (img)
		free(img);
	if (map)
	{
		free_array(map->array);
		free(map);
	}
	ft_printf("%s\n", string);
	exit(1);
}

void	clean_and_free(t_move *game_set)
{
	mlx_delete_texture(game_set->txtr->collectible);
	mlx_delete_texture(game_set->txtr->exit);
	mlx_delete_texture(game_set->txtr->freespace);
	mlx_delete_texture(game_set->txtr->player);
	mlx_delete_texture(game_set->txtr->wall);
	mlx_delete_image(game_set->mlx, game_set->img->collectible);
	mlx_delete_image(game_set->mlx, game_set->img->exit);
	mlx_delete_image(game_set->mlx, game_set->img->freespace);
	mlx_delete_image(game_set->mlx, game_set->img->player);
	mlx_delete_image(game_set->mlx, game_set->img->wall);
	free(game_set->txtr);
	free(game_set->img);
	free_array(game_set->map->array);
	free(game_set->map);
	free(game_set);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
