/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:55:21 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:41:27 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_extension(char *mapfile)
{
	int	len;
	int	fd;

	len = ft_strlen(mapfile);
	fd = open(mapfile, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!(mapfile[len - 4] == '.' && mapfile[len - 3] == 'b'
			&& mapfile[len - 2] == 'e' && mapfile[len - 1] == 'r'))
		return (0);
	return (1);
}
