/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabda <aabda@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:06:19 by aabda             #+#    #+#             */
/*   Updated: 2023/01/03 17:23:30 by aabda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init_img(t_game *g)
{
	g->img.wall = mlx_xpm_file_to_image(g->mlx, "./img/wall.xpm", &g->img.img_width, &g->img.img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "./img/floor.xpm", &g->img.img_width, &g->img.img_height);
	g->img.player_floor = mlx_xpm_file_to_image(g->mlx, "./img/player_floor.xpm", &g->img.img_width, &g->img.img_height);
	g->img.coin = mlx_xpm_file_to_image(g->mlx, "./img/coin.xpm", &g->img.img_width, &g->img.img_height);
	g->img.dclose = mlx_xpm_file_to_image(g->mlx, "./img/dclose.xpm", &g->img.img_width, &g->img.img_height);
	g->img.dclose = mlx_xpm_file_to_image(g->mlx, "./img/dclose.xpm", &g->img.img_width, &g->img.img_height);
	if (!g->img.coin || !g->img.dclose || !g->img.dopen || !g->img.floor
		|| !g->img.player_exit || !g->img.player_floor || !g->img.wall)
		ft_error(-1, NULL, NULL, ERR_INIT_IMG);
}

static void	ft_put_img(t_game *g, int x, int y, const char c)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall, y * 32, x * 32);
	if (c == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.floor, y * 32, x * 32);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_floor, y * 32, x * 32);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.coin, y * 32, x * 32);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.dclose, y * 32, x * 32);
	if (c == 'e')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.dclose, y * 32, x * 32);
}

void	ft_put_img_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
		{
			if (g->map.map[i][j] == '1')
				ft_put_img(g, i, j, '1');
			else if (g->map.map[i][j] == '0')
				ft_put_img(g, i, j, '0');
			else if (g->map.map[i][j] == 'P')
				ft_put_img(g, i, j, 'P');
			else if (g->map.map[i][j] == 'C')
				ft_put_img(g, i, j, 'C');
			else if (g->map.map[i][j] == 'E')
				ft_put_img(g, i, j, 'E');
		}
	}
}
