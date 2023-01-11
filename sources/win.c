/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:03:52 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:42:35 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	win(t_move *game_set)
{
	t_map	*r;

	r = game_set->map;
	mlx_image_to_window(game_set->mlx, game_set->img->freespace,
		r->px * 30, r->py * 30);
	mlx_image_to_window(game_set->mlx, game_set->img->exit,
		r->px * 30, r->py * 30);
	ft_printf("Congratulations, you won the game !\n");
	mlx_close_window(game_set->mlx);
	clean_and_free(game_set);
	mlx_terminate(game_set->mlx);
	exit(0);
}
