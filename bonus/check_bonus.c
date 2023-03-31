/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:06:57 by hece              #+#    #+#             */
/*   Updated: 2023/03/31 17:06:58 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void
	ft_validate_chars(t_game *game)
{
	register size_t	x;
	register size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'E' && game->map[y][x] != 'P'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'X')
				ft_error_message("Map contains at least invalid chr!", game);
			x++;
		}
		y++;
	}
}

void
	ft_validate_amount_chars(t_game *game)
{
	register short	x;
	register short	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->c_count++;
			if (game->map[y][x] == 'E')
				game->e_count++;
			if (game->map[y][x] == 'P')
			{
				game->p_count++;
				game->x = x;
				game->y = y;
			}
			x++;
		}
		y++;
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
		ft_error_message("Map does not contain the required chracters!", game);
}

void
	ft_validate_wall(t_game *game)
{
	register short	x;
	register short	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 && game->map[y][x] != '1')
				ft_error_message("The map must be surrounded by walls!", game);
			if (y == game->rows - 1 && game->map[y][x] != '1')
				ft_error_message("The map must be surrounded by walls!", game);
			if ((x == 0 || x == (game->columns - 1)) && game->map[y][x] != '1')
				ft_error_message("The map must be surrounded by walls!", game);
			x++;
		}
		y++;
	}
}

void
	ft_validate_rectangle(t_game *game)
{
	register short	index;
	register short	y;

	index = ft_strlen(game->map[0]);
	y = 1;
	while (game->map[y])
	{
		if (index != (int)ft_strlen(game->map[y]))
			ft_error_message("The map must be rectangular!", game);
		y++;
	}
	game->rows = y;
	game->columns = index;
}

void
	check_map(t_game *game)
{
	ft_validate_chars(game);
	ft_validate_amount_chars(game);
	ft_validate_wall(game);
	ft_validate_rectangle(game);
	ft_validate_path(game);
}
