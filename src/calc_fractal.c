/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:36:38 by mateus            #+#    #+#             */
/*   Updated: 2023/09/04 03:37:51 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Realiza os cálculos matemáticos para a fractal de Mandelbrot
void	calculate_mandelbrot(t_fractol *f, double x, double y)
{
	int	inter;
	int	color;

	f->c_r = f->min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f->min_im + (y * (f->max_im - f->min_im)) / HEIGTH;
	f->z_r = 0;
	f->z_i = 0;
	inter = 0;
	f->tmp = 0;
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break ;
		inter++;
	}
	if (inter == f->it_max)
		color = 0xfcbdb;
	else
		color = inter * f->color * inter;
	set_pixel_color(f, x, y, color);
}

void	calculate_julia(t_fractol *f, double x, double y)
{
	int	inter;

	f->c_r = f-> min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f-> min_im + (y * (f->max_im - f->min_im)) / HEIGTH;
	f->z_r = f->c_r;
	f->z_i = f->c_i;
	inter = 0;
	f->tmp = 0;
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->arg_re;
		f->z_i = 2 * f->z_i * f->z_r - f->arg_im;
		f->z_r = f->tmp;
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break ;
		inter++;
	}
	if (inter == f->it_max)
		set_pixel_color(f, x, y, 0x000000);
	else
		set_pixel_color(f, x, y, (inter * f->color * inter));
}
