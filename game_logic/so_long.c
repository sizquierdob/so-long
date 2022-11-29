/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizquier <sizquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:02 by sizquier          #+#    #+#             */
/*   Updated: 2022/11/29 20:09:16 by sizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	checkcubextension(char *str, t_complete *game)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			showerror(game, "File Name is not correct");
		else
			close(i);
		return (0);
	}
	showerror(game, "Files without .ber extension is not accepted");
	return (0);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	checkcubextension(argv[1], &game);
	map_reading(&game, argv);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 40),
			(game.heightmap * 40), "solong");
	place_images_in_game(&game);
	adding_in_graphics(&game);
	mlx_key_hook(game.winpointer, controls_working, &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
}
