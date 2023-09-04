/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:15 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/04 03:27:05 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Inicializa os valores padrão da fractal de Mandelbrot
void	mandelbrot_init(t_fractol *f)
{
	f->min_re = -2.2;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = f->min_im + (f->max_re - f->min_re);
	f->it_max = 100;
	f->color = 265;
}

// Cria a fractal de Mandelbrot
void	window_mandelbrot(t_fractol *f)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			calculate_mandelbrot(f, x, y);
			y++;
		}
		x++;
	}
}

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
