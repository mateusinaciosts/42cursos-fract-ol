/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 00:41:56 by mateus            #+#    #+#             */
/*   Updated: 2023/09/06 01:34:42 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

void	tricorn_init(t_fractol *f)
{
	f->min_re = -2.1;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) + f->min_im;
	f->max_iterations = 100;
	f->color = 265;
}

int	calculate_tricorn(t_fractol *f, double const_real, double const_imag)
{
	int		inter;
	double	coord_x;
	double	coord_y;
	double	aux;

	coord_x = const_real;
	coord_y = const_imag;
	inter = 0;
	while (inter < f->max_iterations)
	{
		aux = coord_x * coord_x - coord_y * coord_y + const_real;
		coord_y = -2 * coord_x * coord_y + const_imag;
		coord_x = aux;
		if (coord_x * coord_x + coord_y * coord_y > 4)
			return (inter);
		inter++;
	}
	return (inter);
}
