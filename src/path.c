/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:08:06 by hece              #+#    #+#             */
/*   Updated: 2023/03/31 17:08:07 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void
	ft_floodfill(t_game *game, register int x, register int y)
{
	if (x <= 0 || x >= game->columns || y <= 0 || y >= game->rows
		|| game->map[y][x] == '1' || game->map[y][x] == 'c'
		|| game->map[y][x] == 'o' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'E')
	{
		if (game->map[y][x] == 'E')
			game->exit_posible = 1;
		return ;
	}
	if (game->map[y][x] == 'C')
	{
		game->c_count--;
		game->map[y][x] = 'c';
	}
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	ft_floodfill(game, x, (y + 1));
	ft_floodfill(game, x, (y - 1));
	ft_floodfill(game, (x + 1), y);
	ft_floodfill(game, (x - 1), y);
}

void
	ft_restore(t_game *game)
{
	register short	x;
	register short	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'c')
			{
				game->map[y][x] = 'C';
				game->c_count++;
			}
			else if (game->map[y][x] == 'e')
				game->map[y][x] = 'E';
			else if (game->map[y][x] == 'o')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void
	ft_validate_path(t_game *game)
{
	register short	x;
	register short	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				ft_floodfill(game, x, y);
				if (game->c_count != 0)
					ft_error_message("The map path must be valid!", game);
				ft_restore(game);
				if (game->exit_posible == 0)
					ft_error_message("The map path must be valid!", game);
				return ;
			}
			x++;
		}
		y++;
	}
}
