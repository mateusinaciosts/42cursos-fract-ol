/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:15 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/04 03:37:26 by mateus           ###   ########.fr       */
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
