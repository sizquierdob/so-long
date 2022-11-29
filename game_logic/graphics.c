/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizquier <sizquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:06:51 by sizquier          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:34 by sizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	if (game->map[height][width] == 'P')
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->player, width * 40, height * 40);
		game->playersecond = height;
		game->playerfirst = width;
	}
}

void	place_collectable(t_complete *game, int height, int width)
{
	if (game->map[height][width] == 'C')
	{
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->collectable, width * 40, height * 40);
		game->collectables++;
	}
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/floor.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"game_images/item.xpm", &i, &j);
}

void	place_map(t_complete *game, int height, int width)
{
	if (game->map[height][width] == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 40, height * 40);
	if (game->map[height][width] == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 40, height * 40);
	if (game->map[height][width] == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 40, height * 40);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			place_player (game, height, width);
			place_collectable (game, height, width);
			place_map (game, height, width);
			width++;
		}
		height++;
	}
}
