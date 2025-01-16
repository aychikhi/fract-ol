/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:04:51 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/16 11:22:55 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78
# define MOUSE_BUTTON_UP 5
# define MOUSE_BUTTON_DOWN 4

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define CYAN 0x00FFFF
# define GRAY 0x808080
# define ORANGE 0xFFA500
# define HOT_PINK 0xFF69B4
# define ELECTRIC_BLUE 0x00FF9F
# define ACID_GREEN 0x7FFF00
# define NEON_PURPLE 0x9400D3
# define ELECTRIC_LIME 0xCCFF00
# define PSYCHEDELIC_PURPLE 0xD300C9
# define PLASMA_BLUE 0x00FFEF
# define LASER_RED 0xFF003C
# define UV_PURPLE 0x9B30FF
# define TOXIC_GREEN 0x39FF14
# define RADIOACTIVE_YELLOW 0xFFFF33
# define COSMIC_PURPLE 0x6B3FA0
# define NEON_ORANGE 0xFF6600
# define ALIEN_GREEN 0x00FF8F
# define SYNTHWAVE_PINK 0xFF10F0
# define CYBER_CYAN 0x00FFFF
# define PLASMA_MAGENTA 0xFF00CC
# define VAPORWAVE_PURPLE 0xB19CD9
# define DIGITAL_LIME 0xBFFF00
# define QUANTUM_TURQUOISE 0x40E0D0

# define ERROR_MESSAGE \
	"Please enter \n\t\"./fractol Mandelbrot\" or \
	\n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_win;
	t_img	img;
	double	escp_point;
	int		iterat_num;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

double		atod(char *str);
t_complex	squar_complex(t_complex z);
void		ft_putstr_fd(char *s, int fd);
int			close_win(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
// void		init_burn_data_cz_norm(t_complex z);
void		fractal_render(t_fractal *fractal);
t_complex	sum_complex(t_complex z, t_complex c);
int			key_fun(int keysym, t_fractal *fractal);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			mouse_fun(int button, int x, int y, t_fractal *fractol);
double		scale_value(int pixel, double min, double max, int dimension);

#endif