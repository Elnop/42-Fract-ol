/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:12:00 by lperroti          #+#    #+#             */
/*   Updated: 2023/10/18 07:01:43 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	bool	memdiff(void *p1, void *p2, size_t size)
{
	size--;
	while (size--)
	{
		if (((char *)p1)[size] - ((char *)p2)[size])
			return (true);
	}
	return (false);
}

static bool	has_update(t_mlxapp *papp)
{
	static t_mlxapp	last_check_app;

	if (!memdiff(&last_check_app, papp, sizeof(t_mlxapp)))
		return (false);
	lp_memcpy(&last_check_app, papp, sizeof(t_mlxapp));
	return (true);
}

static	size_t	iter_fractal(t_mlxapp app, t_complex z)
{
	if (app.fractal == JULIA)
		return (iter_julia(app, z));
	if (app.fractal == MANDELBROT)
		return (iter_mandelbrot(app, z));
	if (app.fractal == BURNING_SHIP)
		return (iter_burning_ship(app, z));
	return (0);
}

int	render(t_mlxapp *papp)
{
	t_image		img;
	int			y;
	int			x;
	t_complex	z;
	size_t		iter;

	if (papp->animate)
		animate(papp);
	if (!has_update(papp))
		return (0);
	img = image_new(papp->mlx);
	y = 0;
	while (y < WINDOW_WIDTH)
	{
		x = 0;
		while (x < WINDOW_HEIGHT)
		{
			z = pos_to_complex(*papp, x, y);
			iter = iter_fractal(*papp, z);
			if (iter)
				image_put_px(img, x, y,
					get_color(*papp, iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(papp->mlx, papp->win, img.img, 0, 0);
	image_delete(papp->mlx, img);
	return (0);
}
