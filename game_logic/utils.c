/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sizquier <sizquier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:21:47 by sizquier          #+#    #+#             */
/*   Updated: 2022/11/29 19:35:45 by sizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n / 10)
		ft_putnbr (n / 10);
	ft_putchar (n % 10 + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	freeandexit(t_complete *game)
{
	int	i;

	i = 0;
	if (game->mlxpointer != NULL)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	while (i < game->heightmap)
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	write(1, "\n\033[31m[ so_long closed successfully ]\n", 39);
	exit(0);
}

int	showerror(t_complete *game, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	freeandexit(game);
	return (0);
}
