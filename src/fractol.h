/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:04:30 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/23 02:11:28 by lperroti         ###   ########.fr       */
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

# define JULIA_MAX_ITER 20
# define JULIA_C_R -0.038088
# define JULIA_C_I 0.9754633

typedef struct s_mlxapp {
	void	*mlx;
	void	*win;
}	t_mlxapp;

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

enum e_fractal {
	JULIA,
	MANDALBROT
};

// UTILS
t_complex	pos_to_complex(int x, int y);
int			inter_to_color(size_t iter_count, size_t max_iter);
// APP
bool		init_app(t_mlxapp *app);
int			destroy_app(t_mlxapp *app);
// HOOKS
void		init_hooks(t_mlxapp *app);
// IMAGES
t_image		image_new(void	*mlx);
void		image_delete(void	*mlx, t_image img);
void		image_put_px(t_image img, int x, int y, int color);
// FRACTALS
void		put_julia(t_mlxapp app);
// RENDER
void		render(t_mlxapp app, enum e_fractal fractal);

#endif