/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:09 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/11 11:36:42 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_fun(int keycode, t_fractal *fractal)
{
    if (keycode == ESC_KEY)
    {
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
        exit(0);
    }
    else if (keycode == UP_KEY)
        fractal->shift_y -= 0.5;
    else if (keycode == DOWN_KEY)
        fractal->shift_y += 0.5;
    else if (keycode == LEFT_KEY)
        fractal->shift_x -= 0.5;
    else if (keycode == RIGHT_KEY)
        fractal->shift_x += 0.5;
	fractal_render(fractal);
    return (0);
}