/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:36:38 by mateus            #+#    #+#             */
/*   Updated: 2023/09/06 20:26:13 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

static double	map_real(int x, t_fractol *f)
{
	double	real_range;

	real_range = f->max_real - f->min_real;
	return (f->min_real + (x * real_range) / WIDTH);
}

static double	map_imag(int y, t_fractol *f)
{
	double	imag_range;

	imag_range = f->max_imaginary - f->min_imaginary;
	return (f->min_imaginary + (y * imag_range) / HEIGHT);
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

void	window_tricorn(t_fractol *f)
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
			inter = calculate_tricorn(f, map_real(x, f), map_imag(y, f));
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
