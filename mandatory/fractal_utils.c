/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:53:54 by aychikhi          #+#    #+#             */
/*   Updated: 2025/01/18 11:07:14 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && n > i)
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
		i++;
	}
	return (0);
}

static double	convert(char *str, int i)
{
	double	res;
	double	pow;

	pow = 1;
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		pow /= 10;
		res = res + (str[i] - 48) * pow;
		i++;
	}
	return (res);
}

static int	check_num(char *str, int i)
{
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		i++;
	if (!str[i + 1] || !str[i])
		return (1);
	return (0);
}

double	atod(char *str)
{
	int		i;
	int		sign;
	long	con_int;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (check_num(str, i) == 0)
		return (0);
	con_int = 0;
	while (str[i] != '.' && str[i] >= '0' && str[i] <= '9')
	{
		con_int = con_int * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	return ((convert(str, i) + con_int) * sign);
}
