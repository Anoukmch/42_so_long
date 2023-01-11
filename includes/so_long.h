/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:05:43 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:43:05 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "libs/libs.h"
# include "../mlx42/include/MLX42/MLX42.h"

typedef struct s_map
{
	char	**array;
	int		fd;
	int		row;
	int		column;
	int		p_count;
	int		e_count;
	int		c_count;
	int		i;
	int		j;
	int		px;
	int		py;
	int		move_count;

}				t_map;

typedef struct s_texture
{
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*freespace;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;

}				t_texture;

typedef struct s_image
{
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*freespace;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;

}				t_image;

typedef struct t_move
{
	mlx_t		*mlx;
	t_image		*img;
	t_map		*map;
	t_texture	*txtr;

}				t_move;

int		main(int argc, char **argv);
t_map	*initialize(char *mapfile);
int		check_extension(char *mapfile);
void	create_map(t_map *map);
void	check_walls(t_map *map);
void	check_shape(t_map *map);
size_t	ft_strlen_upgrade(const char *s);
void	check_map_composition(t_map *map);
int		size_map_row(char *mapfile, t_map *map);
void	fill_map(t_map *map);
void	error1(t_map *map, char *string);
void	hook(mlx_key_data_t keydata, void *param);
void	create_texture(t_map *map, t_texture *txtr, t_image *img);
void	create_images(t_map *map, mlx_t *mlx, t_texture *txtr, t_image *img);
void	display_images(mlx_t *mlx, t_texture *txtr, t_image *img, t_map *map);
void	start_game(t_map *map);
void	flood_fill(char **array, int y, int x);
void	check_path(t_map *map);
char	**arraycopy(t_map *map);
void	free_array(char **array);
void	win(t_move *game_set);
void	optimize_display(t_move *game_set, int py_next, int px_next, char l);
void	w_key(t_move *game_set);
void	s_key(t_move *game_set);
void	a_key(t_move *game_set);
void	d_key(t_move *game_set);
t_move	*initialize_move(t_map *map, mlx_t *mlx, t_image *img, t_texture *txtr);
void	clean_and_free(t_move *game_set);
void	error2(t_map *map, t_texture *txtr, t_image	*img, char *string);

#endif
