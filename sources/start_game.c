/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:54:46 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:31 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_images(mlx_t *mlx, t_texture *txtr, t_image *img, t_map *map)
{
	create_texture(map, txtr, img);
	create_images(map, mlx, txtr, img);
	map->i = 0;
	while (map->i < map->row)
	{
		map->j = 0;
		while (map->array[map->i][map->j] && map->array[map->i][map->j] != '\n')
		{
			mlx_image_to_window(mlx, img->freespace, map->j * 30, map->i * 30);
			if (map->array[map->i][map->j] == 'C')
				mlx_image_to_window(mlx, img->collectible,
					map->j * 30, map->i * 30);
			if (map->array[map->i][map->j] == '1')
				mlx_image_to_window(mlx, img->wall, map->j * 30, map->i * 30);
			else if (map->array[map->i][map->j] == 'P')
				mlx_image_to_window(mlx, img->player, map->j * 30, map->i * 30);
			else if (map->array[map->i][map->j] == 'E')
				mlx_image_to_window(mlx, img->exit, map->j * 30, map->i * 30);
			map->j++;
		}
		map->i++;
	}
}

t_move	*initialize_move(t_map *map, mlx_t *mlx, t_image *img, t_texture *txtr)
{
	t_move	*game_set;

	game_set = ft_calloc(1, sizeof(t_move));
	if (!game_set)
		error2(map, txtr, img, "Allocation failed");
	game_set->map = map;
	game_set->mlx = mlx;
	game_set->img = img;
	game_set->txtr = txtr;
	game_set->map->i = 0;
	return (game_set);
}

void	hook(mlx_key_data_t keydata, void	*param)
{
	t_move	*game_set;

	game_set = param;
	if (mlx_is_key_down(game_set->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game_set->mlx);
	if (mlx_is_key_down(game_set->mlx, MLX_KEY_W))
		w_key(game_set);
	if (mlx_is_key_down(game_set->mlx, MLX_KEY_S))
		s_key(game_set);
	if (mlx_is_key_down(game_set->mlx, MLX_KEY_A))
		a_key(game_set);
	if (mlx_is_key_down(game_set->mlx, MLX_KEY_D))
		d_key(game_set);
	if (keydata.key)
		return ;
}

void	start_game(t_map *map)
{
	mlx_t		*mlx;
	t_texture	*txtr;
	t_image		*img;
	t_move		*game_set;

	txtr = ft_calloc(1, sizeof(t_texture));
	img = ft_calloc(1, sizeof(t_image));
	if (!txtr || !img)
		error2(map, NULL, NULL, "Allocation failed");
	mlx = mlx_init(1100, 200, "MLX42", true);
	if (!mlx)
		error2(map, txtr, img, "Window init failed");
	display_images(mlx, txtr, img, map);
	game_set = initialize_move(map, mlx, img, txtr);
	mlx_key_hook(mlx, hook, game_set);
	mlx_loop(mlx);
}
