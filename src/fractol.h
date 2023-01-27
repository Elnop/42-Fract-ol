/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:04:30 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 19:19:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XK_MISCELLANY
# define XK_LATIN1
# include "../includes/minilibx-linux/mlx.h"
# include <X11/keysymdef.h>
# include <math.h>

# include "../includes/liblp_c/liblp.h"

# define WINDOW_HEIGHT 1400
# define WINDOW_WIDTH 1400
# define FRACTAL JULIA
# define MAX_ITER 10
# define C_R -0.743643887037151
# define C_I 0.13182590420533
# define P 2
# define P_ADD 1

typedef enum e_fractal {
	JULIA,
	MANDELBROT,
	BURNING_SHIP,
}	t_fractal;

typedef struct s_complex
{
	double		r;
	double		i;
}	t_complex;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_pixel {
	t_complex	pos;
	size_t		last_iter;
}	t_pixel;

typedef union s_color {
	int	hex;
	struct
	{
		char	r;
		char	g;
		char	b;
		char	a;
	};
}	t_color;

typedef struct s_mlxapp {
	void		*mlx;
	void		*win;
	t_fractal	fractal;
	t_complex	c;
	double		p;
	size_t		max_iter;
	double		zoom;
	double		offset_x;
	double		offset_y;
}	t_mlxapp;

// CONVERTIONS
t_complex	pos_to_complex(t_mlxapp app, int x, int y);
int			inter_to_rgb_hues(size_t iter_count, size_t max_iter);
// APP
bool		init_app(t_mlxapp *app, enum e_fractal fractal, double c_r, double c_i);
int			destroy_app(t_mlxapp *app);
// HOOKS
void		init_hooks(t_mlxapp *app);
// IMAGES
t_image		image_new(void	*mlx);
void		image_delete(void	*mlx, t_image img);
void		image_put_px(t_image img, int x, int y, int color);
int			image_getcolor(t_image img, int x, int y);
// FRACTALS
size_t		iter_mandelbrot(t_mlxapp app, t_complex z);
size_t		iter_absbrot(t_mlxapp app, t_complex z);
size_t		iter_burning_ship(t_mlxapp app, t_complex z);
size_t		iter_julia(t_mlxapp app, t_complex z);
// RENDER
void		render(t_mlxapp app);

#endif