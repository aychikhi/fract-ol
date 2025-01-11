/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:13:49 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/11 10:36:12 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handel_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = scale_value(x, -2, 2, WIDTH) + fractal->shift_x;
	c.y = scale_value(y, 2, -2, HEIGHT) + fractal ->shift_y;
	while (i < fractal->iterat_num)
	{
		z = sum_complex(squar_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escp_point)
		{
			color = scale_value(i, BLACK, WHITE, fractal->iterat_num);
			put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	put_pixel(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handel_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_win,
		fractal->img.img_ptr, 0, 0);
}
