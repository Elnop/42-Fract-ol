/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   launcher.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lperroti <lperroti@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/07/22 09:11:52 by lperroti		  #+#	#+#			 */
/*   Updated: 2023/10/18 05:56:46 by lperroti		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/fractol.h"

void	launcher(t_mlxapp	*app)
{
	mlx_loop_hook(app->mlx, render, app);
}