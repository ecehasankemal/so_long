/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:07:18 by hece              #+#    #+#             */
/*   Updated: 2023/03/31 17:07:19 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void
	ft_validate_file(char *map_path, t_game *game)
{
	register short	index;

	index = ft_strlen(map_path) - 1;
	if (map_path[index] != 'r')
		ft_error_message("The file type must be .ber!", game);
	index--;
	if (map_path[index] != 'e')
		ft_error_message("The file type must be .ber!", game);
	index--;
	if (map_path[index] != 'b')
		ft_error_message("The file type must be .ber!", game);
	index--;
	if (map_path[index] != '.')
		ft_error_message("The file type must be .ber!", game);
}

void
	read_map(char *map_path, t_game *game)
{
	char			*str_map;
	register short	fd;
	char			c;
	register short	count;

	count = 0;
	ft_validate_file(map_path, game);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_message("The file could not be opened!", game);
	while (read(fd, &c, 1) == 1)
		count++;
	if (count == 0)
		ft_error_message("The file is empty!", game);
	str_map = (char *)malloc(sizeof(char) * (count + 1));
	if (!str_map)
		ft_error_message("Failed to allocate memory!", game);
	close(fd);
	fd = open(map_path, O_RDONLY);
	read(fd, str_map, count);
	str_map[count] = '\0';
	close(fd);
	game->map = ft_split(str_map, '\n');
	free(str_map);
}

void
	ft_error_message(char *str, t_game *game)
{
	if (!str)
		ft_printf("Error: ./so_long");
	else
		ft_printf("Error!\n%s\n", str);
	if (game->map)
		ft_free_map_2d(game->map);
	free(game);
	exit(1);
}

void
	ft_free_map_2d(char **map)
{
	register short	index;

	index = 0;
	while (map[index])
	{
		free(map[index]);
		index++;
	}
	free(map);
	map = NULL;
}

void
	init_assets(t_game *game)
{
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./assets/floor.xpm", &game->pxl, &game->pxl);
	game->limits = mlx_xpm_file_to_image(game->mlx,
			"./assets/wall.xpm", &game->pxl, &game->pxl);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &game->pxl, &game->pxl);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			"./assets/collect.xpm", &game->pxl, &game->pxl);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./assets/close.xpm", &game->pxl, &game->pxl);
	game->bomb = mlx_xpm_file_to_image(game->mlx,
			"./assets/bomb.xpm", &game->pxl, &game->pxl);
	game->blank = mlx_xpm_file_to_image(game->mlx,
			"./assets/blank.xpm", &game->pxl, &game->pxl);
}
