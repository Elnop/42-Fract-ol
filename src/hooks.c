/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:41:20 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/24 22:23:17 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hooks_handler(int keycode, t_mlxapp *app)
{
	if (keycode == XK_Escape)
		destroy_app(app);
	if (keycode == XK_x)
	{
		app->max_iter++;
		render(*app, JULIA);
	}
	if (app->max_iter > 0 && keycode == XK_z)
	{
		app->max_iter--;
		render(*app, JULIA);
	}
	if (keycode == XK_Right)
	{
		app->offset_x -= 0.1 / app->zoom;
		render(*app, JULIA);
	}
	if (keycode == XK_Left)
	{
		app->offset_x += 0.1 / app->zoom;
		render(*app, JULIA);
	}
	if (keycode == XK_Up)
	{
		app->offset_y += 0.1 / app->zoom;
		render(*app, JULIA);
	}
	if (keycode == XK_Down)
	{
		app->offset_y -= 0.1 / app->zoom;
		render(*app, JULIA);
	}
	return (1);
}

static int	mouse_hooks_handler(int keycode, int x, int y, t_mlxapp *app)
{
	if (keycode == 4)
	{
		app->zoom /= 2;
		app->offset_x -= (x / WINDOW_WIDTH) * app->zoom;
		app->offset_y -= (y / WINDOW_HEIGHT) * app->zoom;
		render(*app, JULIA);
	}
	if (keycode == 5)
	{
		app->zoom *= 2;
		app->offset_x += (x / WINDOW_WIDTH) * app->zoom;
		app->offset_y += (y / WINDOW_HEIGHT) * app->zoom;
		render(*app, JULIA);
	}
	return (keycode);
}

void	init_hooks(t_mlxapp *app)
{
	mlx_hook(app->win, 2, 1L << 0, hooks_handler, app);
	mlx_hook(app->win, 17, 0, destroy_app, app);
	mlx_mouse_hook(app->win, mouse_hooks_handler, app);
}
