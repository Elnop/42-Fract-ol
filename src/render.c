/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:12:00 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/26 13:52:03 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	size_t	iter_fractal(t_mlxapp app, t_complex z)
{
	if (app.fractal == JULIA)
		return (iter_julia(app, z));
	if (app.fractal == MANDELBROT)
		return (iter_mandelbrot(app, z));
	if (app.fractal == ABSBROT)
		return (iter_absbrot(app, z));
	if (app.fractal == BURNING_SHIP)
		return (iter_burning_ship(app, z));
	return (0);
}

void	render(t_mlxapp app)
{
	t_image	img;
	int		y;
	int		x;
	size_t	iter;

	img = image_new(app.mlx);
	y = 0;
	while (y < WINDOW_WIDTH)
	{
		x = 0;
		while (x < WINDOW_HEIGHT)
		{
			iter = iter_fractal(app, pos_to_complex(app, x, y));
			if (iter)
				image_put_px(img, x, y,
					inter_to_rgb_hues(iter, app.max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app.mlx, app.win, img.img, 0, 0);
	image_delete(app.mlx, img);
}