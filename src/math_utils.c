/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:23:37 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/14 12:16:14 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_value(int pixel, double min, double max, int dimension)
{
	return (min + (max - min) * ((double)pixel / (double)dimension));
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}

t_complex	squar_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
