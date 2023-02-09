/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/09 23:32:41 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pos_to_complex(t_mlxapp app, int x, int y)
{
	double	r;
	double	i;

	r = (-2 / app.zoom) + app.offset_x + x
		* (
			((2 / app.zoom + app.offset_x)
				- (-2 / app.zoom + app.offset_x)) / WINDOW_WIDTH
			);
	i = (-2 / app.zoom) + app.offset_y + y
		* (((2 / app.zoom + app.offset_y)
				- (-2 / app.zoom + app.offset_y)) / WINDOW_HEIGHT);
	return ((t_complex){
		.r = r,
		.i = i
	});
}

int	inter_to_rgb_hues(size_t iter_count, size_t max_iter)
{
	t_color	color;
	float	hue;

	hue = (float)iter_count / max_iter * 360;
	if (hue > 300)
		color = (t_color){.b = (char)255, .g = (char)((240 - hue) / 60 * 255)};
	else if (hue > 240)
		color = (t_color){.g = (char)255, .b = (char)((hue - 120) / 60 * 255)};
	else if (hue > 180)
		color = (t_color){.g = (char)255, .r = (char)((120 - hue) / 60 * 255)};
	else if (hue > 120)
		color = (t_color){.r = (char)255, .g = (char)(hue / 60 * 255)};
	else if (hue > 60)
		color = (t_color){.b = (char)255, .r = (char)((hue - 240) / 60 * 255)};
	else
		color = (t_color){.r = (char)255, .b = (char)((360 - hue) / 60 * 255)};
	return (color.hex);
}

int	inter_to_b_hues(size_t iter_count, size_t max_iter)
{
	t_color	color;

	color = (t_color){.b = (char)100 + (iter_count / max_iter * 155)};
	return (color.hex);
}

int	get_color(t_mlxapp app, size_t iter_count)
{
	if (app.color == 1)
		return (inter_to_rgb_hues(iter_count, app.max_iter));
	else
		return (inter_to_b_hues(iter_count, app.max_iter));
}