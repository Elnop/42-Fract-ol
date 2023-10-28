/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   app_init_destroy.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lperroti <lperroti@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/20 13:00:14 by lperroti		  #+#	#+#			 */
/*   Updated: 2023/10/18 07:10:17 by lperroti		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	init_app(t_mlxapp *app, enum e_fractal fractal, double c_r, double c_i)
{
	app->mlx = mlx_init();
	if (!app->mlx)
		return (false);
	app->win = mlx_new_window(app->mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "fractol");
	if (!app->win)
		return (false);
	app->fractal = fractal;
	if (!c_r)
		c_r = C_R;
	if (!c_i)
		c_i = C_I;
	app->c = (t_complex){c_r, c_i};
	app->p = P;
	app->max_iter = MAX_ITER;
	app->zoom = 1.0;
	app->offset_x = 0.0;
	app->offset_y = 0.0;
	app->color = 0;
	app->mouse_pos_to_const = false;
	app->animate = false;
	app->animate_frame = 0;
	app->animate_frame_time = 5000;
	return (true);
}

int	destroy_app(t_mlxapp *app)
{
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	exit(0);
	return (1);
}
