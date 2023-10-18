/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:41:20 by lperroti          #+#    #+#             */
/*   Updated: 2023/10/18 07:04:36 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

static void	zoom_events(int keycode, t_mlxapp *app)
{
	if (keycode == XK_Right)
		app->offset_x -= 0.1 / app->zoom;
	if (keycode == XK_Left)
		app->offset_x += 0.1 / app->zoom;
	if (keycode == XK_Up)
		app->offset_y += 0.1 / app->zoom;
	if (keycode == XK_Down)
		app->offset_y -= 0.1 / app->zoom;
}

static int	hooks_handler(int keycode, t_mlxapp *app)
{
	if (keycode == XK_a)
	{
		app->animate = !app->animate;
		if (app->animate)
			app->c = (t_complex){-2, -2};
	}
	if (keycode == XK_w)
		app->mouse_pos_to_const = !app->mouse_pos_to_const;
	if (keycode == XK_c && app->color)
		app->color = 0;
	else if (keycode == XK_c && !app->color)
		app->color = 1;
	(void)(keycode == XK_i && (app->max_iter = 10));
	if (keycode == XK_r)
	{
		app->zoom = 1.0;
		app->offset_x = 0;
		app->offset_y = 0;
	}
	(void)((keycode == XK_p) && (app->p += P_ADD));
	(void)((keycode == XK_o) && (app->p -= P_ADD));
	if (keycode == XK_Escape)
	{
		destroy_app(app);
		exit(0);
	}
	if (keycode == XK_x)
		app->max_iter = app->max_iter * 1.1 + 1;
	if (app->max_iter > 0 && keycode == XK_z)
		app->max_iter = app->max_iter / 1.1 - 1;
	zoom_events(keycode, app);
	return (1);
}

static int	mousemove_handler(int x, int y, t_mlxapp *app)
{
	if (app->mouse_pos_to_const)
		app->c = pos_to_complex(*app, x, y);
	return (0);
}

static int	mouse_hooks_handler(int keycode, int x, int y, t_mlxapp *app)
{
	if (keycode == 4)
		app->zoom /= 2;
	if (keycode == 5)
	{
		app->zoom *= 2;
		app->offset_x += ((double)x - WINDOW_WIDTH / 2) / WINDOW_WIDTH
			* (
				(2 / app->zoom + app->offset_x)
				- (-2 / app->zoom + app->offset_x)
				);
		app->offset_y += ((double)y - WINDOW_HEIGHT / 2) / WINDOW_HEIGHT
			* (
				(2 / app->zoom + app->offset_y)
				- (-2 / app->zoom + app->offset_y)
				);
	}
	return (keycode);
}

void	init_hooks(t_mlxapp *app)
{
	mlx_hook(app->win, 2, 1L << 0, hooks_handler, app);
	mlx_hook(app->win, 17, 0, destroy_app, app);
	mlx_mouse_hook(app->win, mouse_hooks_handler, app);
	mlx_hook(app->win, 6, 1L << 6, mousemove_handler, app);
}
