/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:09 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/18 12:30:43 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	exit(0);
	return (0);
}

int	key_fun(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
		exit(0);
	}
	return (0);
}

int	mouse_fun(int button, int x, int y, t_fractal *fractol)
{
	x = (int)x;
	y = (int)y;
	if (button == 4)
		fractol->zoom *= 0.9;
	else if (button == 5)
		fractol->zoom *= 1.1;
	fractal_render(fractol);
	return (0);
}
