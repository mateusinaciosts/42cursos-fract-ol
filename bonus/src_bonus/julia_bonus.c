/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:19 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/05 22:08:40 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

void	julia_init(t_fractol *f)
{
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = (f->max_re - f->min_re) * HEIGHT / WIDTH + f->min_im;
	f->max_iterations = 250;
	f->color = 265;
}

int	calculate_julia(t_fractol *f, double const_real, double const_imag)
{
	double	coord_x;
	double	coord_y;
	double	aux;
	int		inter;

	coord_x = const_real;
	coord_y = const_imag;
	inter = 0;
	while (inter < f->max_iterations)
	{
		aux = coord_x * coord_x - coord_y * coord_y + f->real_argument;
		coord_y = 2 * coord_x * coord_y - f->imaginary_argument;
		coord_x = aux;
		if (coord_x * coord_x + coord_y * coord_y > 4)
			return (inter);
		inter++;
	}
	return (inter);
}
