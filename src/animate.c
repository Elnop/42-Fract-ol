/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 05:56:32 by lperroti          #+#    #+#             */
/*   Updated: 2023/10/18 08:39:06 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    animate(t_mlxapp *papp)
{
    static double anime_born = ANIMATE_BORN;
    static bool born_is_growing;

    if (!papp->animate_frame)
    {
        papp->c.r += ANIMATE_STEP;
        if (papp->c.r >= anime_born)
            papp->animate_frame++;
    }
    else if (papp->animate_frame == 1)
    {
        papp->c.i += ANIMATE_STEP;
        if (papp->c.i >= anime_born)
            papp->animate_frame++;
    }
    else if (papp->c.r > -anime_born)
    {
        papp->c.r -= ANIMATE_STEP;
        if (papp->c.r <= -anime_born)
            papp->animate_frame++;
    }
    else if (papp->c.i > -anime_born)
    {
        papp->c.i -= ANIMATE_STEP;
        if (papp->c.i <= -anime_born)
        {
            if (!born_is_growing)
            {
                if (anime_born > 0.2)
                    anime_born -= 0.1;
                else
                {
                    born_is_growing = true;
                    anime_born += 0.1;
                }
            }
            else
            {
                if (anime_born < ANIMATE_BORN)
                    anime_born += 0.1;
                else
                {
                    born_is_growing = false;
                    anime_born -= 0.1;
                }
            }
            papp->animate_frame = 0;
        }
    }
    usleep(50000);
}
