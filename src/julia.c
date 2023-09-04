/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:19 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/04 03:37:23 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_init(t_fractol *f)
{
	f->zoom = 200;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) * HEIGTH / WIDTH + f->min_im;
	f->it_max = 250;
	f->color = 265;
}

void	*window_julia(t_fractol *f)
{
	double	x;
	double	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			calculate_julia(f, y, x);
			y++;
		}
		x++;
	}
	return (0);
}
