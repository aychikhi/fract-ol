/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:04:51 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/09 13:08:54 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACOL_H
# define FRACOL_H

# ifndef ERROR_MESSAGE
#  define ERROR_MESSAGE "Please enter \n\t\"./fractol Mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
# endif

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int bpp; // bit per pixel
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_win;

}			t_factal;
// typedef struct s_complex
// {
// 	//x
// 	double real;
// 	//imaginaire
// 	double i;
// }t_complex;
# include "MLX/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif