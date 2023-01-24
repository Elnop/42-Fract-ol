/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:28:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/24 21:47:49 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	julia_px_iter(t_complex z, size_t	max_iter)
{
	size_t	iter;

	iter = 0;
	while (iter < max_iter)
	{
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + JULIA_C_R,
			.i = 2 * z.r * z.i + JULIA_C_I
		};
		iter++;
		if (z.r * z.r + z.i * z.i >= 4)
			return (iter);
	}
	return (0);
}

void	put_julia(t_mlxapp app)
{
	t_image	img;
	int		y;
	int		x;
	size_t	last_iter;

	img = image_new(app.mlx);
	y = 0;
	while (y < WINDOW_WIDTH)
	{
		x = 0;
		while (x < WINDOW_HEIGHT)
		{
			last_iter = julia_px_iter(pos_to_complex(app, x, y), app.max_iter);
			if (last_iter)
				image_put_px(img, x ,y ,
					inter_to_rgb_hues(last_iter, app.max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app.mlx, app.win, img.img, 0, 0);
	image_delete(app.mlx, img);
}
