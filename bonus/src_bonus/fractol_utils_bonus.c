/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:35 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/08 17:34:00 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

double	parse_double(const char *str)
{
	int		sign;
	double	result;
	double	power;
	int		i;

	sign = 1;
	result = 0;
	power = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i++] - '0';
		power *= 10;
	}
	return (sign * result / power);
}

int	close_win(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img_ptr);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	color = mlx_get_color_value(f->mlx, color);
	ft_memcpy(f->image + 4 * WIDTH * y + x * 4, &color, sizeof(int));
}

int	check_double(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '.')
		return (0);
	while (*str && *str != '.')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (*str == '.')
	{
		if (!ft_isdigit(*(str + 1)))
			return (0);
		str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
	}
	return (1);
}
