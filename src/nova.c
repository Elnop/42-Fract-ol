/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:44:07 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/26 04:07:11 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

size_t	nova_px_iter(t_mlxapp app, t_complex z, size_t max_iter)
{
	size_t		iter;
	double		abs_z;

	iter = 0;
	while (iter < max_iter)
	{
		abs_z = sqrt(z.r * z.r + z.i * z.i);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + app.c.r,
			.i = 2 * fabs(z.r) * fabs(z.i) + app.c.i
		};
		iter++;
		if (z.r * z.r + z.i * z.i >= 4)
			return (iter);
	}
	return (0);
}

void	put_nova(t_mlxapp app)
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
			last_iter = nova_px_iter(app, pos_to_complex(app, x, y),
					app.max_iter);
			if (last_iter)
				image_put_px(img, x, y,
					inter_to_rgb_hues(last_iter, app.max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app.mlx, app.win, img.img, 0, 0);
	image_delete(app.mlx, img);
}
