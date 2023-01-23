/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/23 02:18:52 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	pos_to_complex(int x, int y)
{
	return ((t_complex){
		.r = (2.0 * (x - WINDOW_WIDTH / 2) / (0.5 * WINDOW_HEIGHT)),
		.i = (2.0 * (y - WINDOW_HEIGHT / 2) / (0.5 * WINDOW_WIDTH))
	});
}

int	inter_to_rgb_hues(size_t iter_count, size_t max_iter)
{
	int		r;
	int		g;
	int		b;
	float	hue;

	hue = (float)iter_count / max_iter * 360;
	if (hue < 60) 
	{
        r = (int) ((hue - 240) / 60 * 255);
        g = 0;
        b = 255;
    }
	else if (hue < 120)
	{
        r = 255;
        g = (int) (hue / 60 * 255);
        b = 0;
    }
	else if (hue < 180)
	{
        r = (int) ((120 - hue) / 60 * 255);
        g = 255;
        b = 0;
    }
	else if (hue < 240)
	{
        r = 0;
        g = 255;
        b = (int) ((hue - 120) / 60 * 255);
    }
	else if (hue < 300) {
        r = 0;
        g = (int) ((240 - hue) / 60 * 255);
        b = 255;
    }
	else
	{
        r = 255;
        g = 0;
        b = (int) ((360 - hue) / 60 * 255);
    }
    return (r << 16) | (g << 8) | b;
}