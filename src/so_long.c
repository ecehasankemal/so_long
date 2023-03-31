/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:00:09 by hece              #+#    #+#             */
/*   Updated: 2023/03/31 17:08:15 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void
	close_img(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->limits)
		mlx_destroy_image(game->mlx, game->limits);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

void
	init_data(t_game *game)
{
	game->map = NULL;
	game->c_count = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->mov = 0;
	game->x = 0;
	game->y = 0;
	game->rows = 0;
	game->columns = 0;
	game->exit_posible = 0;
}

int
	main(int ac, char **av)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_data(game);
	if (ac != 2)
		ft_error_message("The program must be run with a map argument!", game);
	read_map(av[1], game);
	check_map(game);
	ft_window(game);
	return (0);
}
