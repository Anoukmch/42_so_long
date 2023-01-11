/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:05:07 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:38 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	optimize_display(t_move *game_set, int py_next, int px_next, char l)
{
	t_map	*r;

	r = game_set->map;
	mlx_image_to_window(game_set->mlx, game_set->img->freespace,
		r->px * 30, r->py * 30);
	if (r->array[r->py][r->px] == 'E')
		mlx_image_to_window(game_set->mlx, game_set->img->exit,
			r->px * 30, r->py * 30);
	if (l != 'E')
		mlx_image_to_window(game_set->mlx, game_set->img->freespace,
			px_next * 30, py_next * 30);
}

void	w_key(t_move *game_set)
{
	t_map	*r;

	r = game_set->map;
	if (r->array[r->py][r->px] == 'P')
		r->array[r->py][r->px] = '0';
	if (r->array[r->py - 1][r->px] != '1')
	{
		if (r->array[r->py - 1][r->px] == 'C')
		{
			r->i++;
			r->array[r->py - 1][r->px] = '0';
		}
		optimize_display(game_set, r->py - 1, r->px,
			r->array[r->py - 1][r->px]);
		if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
			win(game_set);
		r->py--;
		r->move_count++;
		mlx_image_to_window(game_set->mlx, game_set->img->player,
			r->px * 30, r->py * 30);
		ft_printf("Moves count : %d\n", r->move_count);
	}
	if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
		win(game_set);
}

void	s_key(t_move *game_set)
{
	t_map	*r;

	r = game_set->map;
	if (r->array[r->py][r->px] == 'P')
		r->array[r->py][r->px] = '0';
	if (r->array[r->py + 1][r->px] != '1')
	{
		if (r->array[r->py + 1][r->px] == 'C')
		{
			r->i++;
			r->array[r->py + 1][r->px] = '0';
		}
		optimize_display(game_set, r->py + 1, r->px,
			r->array[r->py + 1][r->px]);
		if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
			win(game_set);
		r->py++;
		r->move_count++;
		mlx_image_to_window(game_set->mlx, game_set->img->player,
			r->px * 30, r->py * 30);
		ft_printf("Moves count : %d\n", r->move_count);
	}
	if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
		win(game_set);
}

void	a_key(t_move *game_set)
{
	t_map	*r;

	r = game_set->map;
	if (r->array[r->py][r->px] == 'P')
		r->array[r->py][r->px] = '0';
	if (r->array[r->py][r->px - 1] != '1')
	{
		if (r->array[r->py][r->px - 1] == 'C')
		{
			r->i++;
			r->array[r->py][r->px - 1] = '0';
		}
		optimize_display(game_set, r->py, r->px - 1,
			r->array[r->py][r->px - 1]);
		if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
			win(game_set);
		r->px--;
		r->move_count++;
		mlx_image_to_window(game_set->mlx, game_set->img->player,
			r->px * 30, r->py * 30);
		ft_printf("Moves count : %d\n", r->move_count);
	}
	if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
		win(game_set);
}

void	d_key(t_move *game_set)
{
	t_map	*r;

	r = game_set->map;
	if (r->array[r->py][r->px] == 'P')
		r->array[r->py][r->px] = '0';
	if (r->array[r->py][r->px + 1] != '1')
	{
		if (r->array[r->py][r->px + 1] == 'C')
		{
			r->i++;
			r->array[r->py][r->px + 1] = '0';
		}
		optimize_display(game_set, r->py, r->px + 1,
			r->array[r->py][r->px + 1]);
		if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
			win(game_set);
		r->px++;
		r->move_count++;
		mlx_image_to_window(game_set->mlx, game_set->img->player,
			r->px * 30, r->py * 30);
		ft_printf("Moves count : %d\n", r->move_count);
	}
	if (r->i == r->c_count && r->array[r->py][r->px] == 'E')
		win(game_set);
}
