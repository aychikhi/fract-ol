/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:05:00 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/09 13:05:03 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if ((ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		printf("hh");
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
}

// t_complex	plane_cord(t_complex c)
// {
// 	t_complex z;
// 	z.real = 0;
// 	z.i = 0;
// 	double tmp_z;
// 	tmp_z = (z.real * z.real) - (z.i * z.i);
// 	z.i += 2 * z.i * z.real;
// 	z.real = tmp_z;
// 	z.real += c.real;
// 	z.i += c.i;
// 	return (z);
// }
// int main()
// {
// 	mlx_t *win = mlx_init(500, 500, "Mandelbrot", false);
// 	mlx_image_t *img = mlx_new_image(win, 500, 500);
// 	mlx_image_to_window(win, img, 0, 0);
// 	mlx_loop(win);
// }