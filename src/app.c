/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:00:14 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/24 21:46:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	init_app(t_mlxapp *app, enum e_fractal fractal)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (false);
	app->win = mlx_new_window(app->mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "fractol");
	if (!app->win)
		return (false);
	if (fractal == JULIA)
		app->max_iter = JULIA_MAX_ITER;
	app->zoom = 1.0;
	app->offset_x = 0.0;
	app->offset_y = 0.0;
	return (true);
}

int	destroy_app(t_mlxapp *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
	return (1);
}
