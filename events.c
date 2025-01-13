/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:48:09 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/13 17:33:01 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_win);
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	free(fractal->mlx_connection);
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
	else if (keycode == UP_KEY)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == DOWN_KEY)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == LEFT_KEY)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == RIGHT_KEY)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == PLUS_KEY)
		fractal->iterat_num += 10;
	else if (keycode == MINUS_KEY)
		fractal->iterat_num -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_fun(int button, int x, int y, t_fractal *fractol)
{
	double			mouse_x;
	double			mouse_y;
	const double	zoom_factor = 0.1;

	mouse_x = fractol->shift_x + (x * (fractol->zoom / WIDTH));
	mouse_y = fractol->shift_y + (y * (fractol->zoom / HEIGHT));
	if (button == 4)
	{
		fractol->zoom *= (1 - zoom_factor);
	}
	else if (button == 5)
	{
		fractol->zoom *= (1 + zoom_factor);
	}
	fractol->shift_x = mouse_x - (x * (fractol->zoom / WIDTH));
	fractol->shift_y = mouse_y - (y * (fractol->zoom / HEIGHT));
	fractal_render(fractol);
	return (0);
}
