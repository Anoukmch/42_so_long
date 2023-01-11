/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:23:49 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/01/11 15:41:21 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == 0)
			error1(NULL, "Wrong extension");
		map = initialize(argv[1]);
		create_map(map);
		start_game(map);
	}
	else
		error1(NULL, "Wrong input number");
}
