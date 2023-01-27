/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:28:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 19:31:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	iter_julia(t_mlxapp app, t_complex z)
{
	size_t	iter;

	iter = 0;
	while (iter < app.max_iter)
	{
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + app.c.r,
			.i = 2 * z.r * z.i + app.c.i
		};
		iter++;
		if (z.r * z.r + z.i * z.i >= 4)
			return (iter);
	}
	return (0);
}
