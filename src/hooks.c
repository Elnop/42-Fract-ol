/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:41:20 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/23 04:50:46 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hooks_handler(int keycode, t_mlxapp *app)
{
	if (keycode == XK_Escape)
		destroy_app(app);
	if (keycode == XK_Right)
	{
		app->max_iter++;
		render(*app, JULIA);
	}
	if (app->max_iter > 0 && keycode == XK_Left)
	{
		app->max_iter--;
		render(*app, JULIA);
	}
	return (1);
}

void	init_hooks(t_mlxapp *app)
{
	mlx_hook(app->win, 2, 1L << 0, hooks_handler, app);
	mlx_hook(app->win, 17, 0, destroy_app, app);
}
