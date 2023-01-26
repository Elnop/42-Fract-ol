/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absbrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:18:37 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/26 13:53:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

size_t	iter_absbrot(t_mlxapp app, t_complex z)
{
	size_t		iter;
	t_complex	z0;

	iter = 0;
	z.r = fabs(z.r);
	z.i = fabs(z.i);
	z0 = z;
	while (iter < app.max_iter)
	{
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + z0.r,
			.i = 2 * z.r * z.i + z0.i
		};
		iter++;
		if (z.r * z.r + z.i * z.i >= 4)
			return (iter);
	}
	return (0);
}
