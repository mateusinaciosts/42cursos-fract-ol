/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:15 by matsanto          #+#    #+#             */
/*   Updated: 2023/08/31 14:03:17 by matsanto         ###   ########.fr       */
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
void	mandelbrot(t_fractol *f)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			mandelbrot_math(f, x, y); // Troca a ordem dos argumentos
			y++;
		}
		x++;
	}
}

// Realiza os cálculos matemáticos para a fractal de Mandelbrot
void	mandelbrot_math(t_fractol *f, double x, double y)
{
	int	inter;

	// Calcula os valores complexos correspondentes aos pixels
	f->c_r = f->min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f->min_im + (y * (f->max_im - f->min_im)) / HEIGTH;

	// Inicializa valores para o loop de cálculo
	f->z_r = 0;
	f->z_i = 0;
	inter = 0;
	f->tmp = 0;

	// Realiza o loop de cálculo da fractal
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;

		// Verifica se o ponto está fora da região da fractal
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break;

		inter++;
	}

	// Define a cor do pixel com base na iteração
	int color = (inter == f->it_max) ? 0xfcbdb : (inter * f->color * inter);
	put_pxl_to_img(f, x, y, color);
}
