/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_two_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:07:11 by hece              #+#    #+#             */
/*   Updated: 2023/03/31 17:07:12 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void
	ft_put_bomb(t_game *game, register int x, register int y)
{
	if (game->bomb)
		mlx_destroy_image(game->mlx, game->bomb);
	game->bomb = mlx_xpm_file_to_image(game->mlx, "./assets/bomb.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bomb, game->pxl
		* x, game->pxl * y);
}

void
	ft_put_blank(t_game *game, register int x, register int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->blank, game->pxl
		* x, game->pxl * y);
}
