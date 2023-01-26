/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:36:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/26 12:26:47 by lperroti         ###   ########.fr       */
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

static t_fractal args_to_fractal(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		fractal = JULIA;
	else if (!lp_strncmp(av[1], "julia", 20))
		fractal = JULIA;
	else if (!lp_strncmp(av[1], "mandelbrot", 20))
		fractal = MANDELBROT;
	else if (!lp_strncmp(av[1], "burning_ship", 20))
		fractal = BURNING_SHIP;
	else if (!lp_strncmp(av[1], "absbrot", 20))
		fractal = ABSBROT;
	else if (!lp_strncmp(av[1], "novabrot", 20))
		fractal = NOVABROT;
	else
	{
		lp_putendl_fd("INVALID ARGS", 2);
		exit(0);
	}
	return (fractal);
}

int	main(int ac, char **av)
{
	t_mlxapp	app;

	if (!init_app(&app, args_to_fractal(ac, av)))
		return ((void)lp_putendl_fd("Can't init MLX App", 1), 1);
	init_hooks(&app);
	render(app);
	mlx_loop(app.mlx);
	return (1);
}
