/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:36:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/23 04:50:25 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
 
 coordonates -> complex
 t_complex	pos_to_complex(int x, int y);

        2
        |
        |
      I |
        |
     -2 |______________________ 2
       -2         R

  color the pixels if they go out of borns
  iter_count -> color hexa
  int	inter_to_color(size_t iter_count);

-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_*/

#include "fractol.h"

#include <stdio.h>

void	render(t_mlxapp app, enum e_fractal fractal)
{
	if (fractal == JULIA)
		put_julia(app);
}

int	main(void)
{
	t_mlxapp	app;

	if (!init_app(&app, JULIA))
		return ((void)lp_putendl_fd("Can't init MLX App", 1), 1);
	init_hooks(&app);
	render(app, JULIA);
	mlx_loop(app.mlx);
	return (1);
}
