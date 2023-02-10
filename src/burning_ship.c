/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:42:33 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/10 02:27:10 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	iter_burning_ship(t_mlxapp app, t_complex c)
{
	size_t		iter;
	t_complex	z;

	iter = 0;
	z = (t_complex){};
	while (iter < app.max_iter)
	{
		if (z.r * z.r + z.i * z.i >= 4)
			return (iter);
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = (t_complex){
			.r = z.r * z.r - z.i * z.i + c.r,
			.i = 2 * z.r * z.i + c.i
		};
		iter++;
	}
	return (0);
}
