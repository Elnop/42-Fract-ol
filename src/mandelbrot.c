/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:22:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 19:30:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

size_t	iter_mandelbrot(t_mlxapp app, t_complex c)
{
	size_t		iter;
	t_complex	z;

	iter = 0;
	z = (t_complex){};
	while (iter < app.max_iter)
	{
		if (fabs(z.r * z.r + z.i * z.i) >= 4)
			return (iter);
		z = (t_complex){
			.r = pow(z.r * z.r + z.i * z.i, app.p / 2)
			* cos(app.p * atan2(z.i, z.r)) + c.r,
			.i = pow(z.r * z.r + z.i * z.i, app.p / 2)
			* sin(app.p * atan2(z.i, z.r)) + c.i
		};
		iter++;
	}
	return (0);
}
