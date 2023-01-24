/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:24:55 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/24 21:07:41 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	image_new(void	*mlx)
{
	t_image img;

	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!img.img)
		return ((t_image){});
	img.addr = mlx_get_data_addr(
			img.img,
			&img.bits_per_pixel,
			&img.line_length,
			&img.endian
			);
	return (img);
}

void	image_delete(void	*mlx, t_image img)
{
	mlx_destroy_image(mlx, img.img);
	img = (t_image){};
}

void	image_put_px(t_image img, int x, int y, int color)
{
	img.addr += (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(int *)img.addr = color;
}

int	image_getcolor(t_image img, int x, int y)
{
	img.addr += (y * img.line_length + x * (img.bits_per_pixel / 8));
	return (*(int *)img.addr);
}