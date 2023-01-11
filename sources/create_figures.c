/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:23:02 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:37 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_texture(t_map *map, t_texture *txtr, t_image *img)
{
	txtr->player = mlx_load_png("./Assets/Player.png");
	txtr->wall = mlx_load_png("./Assets/Wall.png");
	txtr->freespace = mlx_load_png("./Assets/Freespace.png");
	txtr->collectible = mlx_load_png("./Assets/Collectible.png");
	txtr->exit = mlx_load_png("./Assets/Exit.png");
	if (!txtr->player || !txtr->wall || !txtr->freespace
		|| !txtr->collectible || !txtr->exit)
		error2(map, txtr, img, "Textures creation failed");
}

void	create_images(t_map *map, mlx_t *mlx, t_texture *txtr, t_image *img)
{
	img->player = mlx_texture_to_image(mlx, txtr->player);
	img->wall = mlx_texture_to_image(mlx, txtr->wall);
	img->freespace = mlx_texture_to_image(mlx, txtr->freespace);
	img->collectible = mlx_texture_to_image(mlx, txtr->collectible);
	img->exit = mlx_texture_to_image(mlx, txtr->exit);
	if (!img->player || !img->wall || !img->freespace
		|| !img->collectible || !img->exit)
		error2(map, txtr, img, "Images creation failed");
}
