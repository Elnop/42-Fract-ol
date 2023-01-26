/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:12:00 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/26 01:13:20 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_mlxapp app)
{
	if (app.fractal == JULIA)
		put_julia(app);
	if (app.fractal == MANDELBROT)
		put_mandelbrot(app);
	if (app.fractal == NOVA)
		put_nova(app);
	if (app.fractal == NOVABROT)
		put_novabrot(app);
}