/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:41:20 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/23 01:45:47 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hooks_handler(int keycode, t_mlxapp *app)
{
	if (keycode == XK_Escape)
		destroy_app(app);
	return (1);
}

void	init_hooks(t_mlxapp *app)
{
	mlx_hook(app->win, 2, 1L << 0, hooks_handler, app);
	mlx_hook(app->win, 17, 0, destroy_app, app);
}
