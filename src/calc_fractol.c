/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:36:38 by mateus            #+#    #+#             */
/*   Updated: 2023/09/05 18:06:25 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	map_real(int x, t_fractol *f)
{
	double	real_range;

	real_range = f->max_re - f->min_re;
	return (f->min_re + (x * real_range) / WIDTH);
}

static double	map_imag(int y, t_fractol *f)
{
	double	imag_range;

	imag_range = f->max_im - f->min_im;
	return (f->min_im + (y * imag_range) / HEIGHT);
}

void	window_mandelbrot(t_fractol *f)
{
	double	x;
	double	y;
	int		inter;
	int		color;

	x = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			inter = calculate_mandelbrot(f, map_real(x, f), map_imag(y, f));
			if (inter == f->max_iterations)
				color = 0x000000;
			else
				color = inter * f->color * inter;
			set_pixel_color(f, x, y, color);
		}
	}
}

void	window_julia(t_fractol *f)
{
	double	x;
	double	y;
	int		inter;

	x = 0;
	inter = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			inter = calculate_julia(f, map_real(x, f), map_imag(y, f));
			if (inter == f->max_iterations)
				set_pixel_color(f, x, y, 0x000000);
			else
				set_pixel_color(f, x, y, (inter * f->color * inter));
		}
	}
}
