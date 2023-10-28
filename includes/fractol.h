/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fractol.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lperroti <lperroti@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/19 21:04:30 by lperroti		  #+#	#+#			 */
/*   Updated: 2023/10/18 08:37:17 by lperroti		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define XK_MISCELLANY
# define XK_LATIN1
# include "../libs/minilibx-linux/mlx.h"
# include <X11/keysymdef.h>
# include <math.h>

# include "../libs/liblp_c/liblp.h"

# define WINDOW_HEIGHT 700
# define WINDOW_WIDTH 700
# define FRACTAL JULIA
# define MAX_ITER 20
# define ANIMATE_BORN 1
# define ANIMATE_STEP 0.03
# define C_R -0.8
# define C_I 0.156
# define P 2
# define P_ADD 1

typedef enum e_fractal {
	JULIA,
	MANDELBROT,
	BURNING_SHIP,
	PHOENIX
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
		char	b;
		char	g;
		char	r;
		char	a;
	};
}	t_color;

typedef struct s_mlxapp {
	void			*mlx;
	void			*win;
	t_fractal		fractal;
	t_complex		c;
	double			p;
	size_t			max_iter;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				color;
	bool			mouse_pos_to_const;
	bool			animate;
	size_t			animate_frame;
	unsigned int	animate_frame_time;
}	t_mlxapp;

// CONVERTIONS
t_complex	pos_to_complex(t_mlxapp app, int x, int y);
int			get_color(t_mlxapp app, size_t iter_count);
// APP
bool		init_app(t_mlxapp *app, enum e_fractal fractal,
				double c_r, double c_i);
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
void		animate(t_mlxapp *papp);
void		launcher(t_mlxapp	*app);
int			render(t_mlxapp *app);

#endif