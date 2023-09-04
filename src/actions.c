/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:38 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/04 17:27:53 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_fractol *f, double re_diff, double im_diff)
{
	f->min_re += re_diff;
	f->max_re -= re_diff;
	f->min_im += im_diff;
	f->max_im -= im_diff;
}

void	zoom_out(t_fractol *f, double re_diff, double im_diff)
{
	f->min_re -= re_diff;
	f->max_re += re_diff;
	f->min_im -= im_diff;
	f->max_im += im_diff;
}

int	zoom_interaction(int key, t_fractol *f)
{
	double	zoom;
	double	re_diff;
	double	im_diff;

	zoom = 0.1;
	re_diff = (f->max_re - f->min_re) * zoom;
	im_diff = (f->max_im - f->min_im) * zoom;
	if (key == 4)
	{
		zoom_in(f, re_diff, im_diff);
	}
	else if (key == 5)
	{
		zoom_out(f, re_diff, im_diff);
	}
	return (1);
}

void	change_color(t_fractol *f)
{
	static int	colors;

	colors++;
	if (colors == 6)
		colors = 0;
	if (colors == 0)
		f->color = 265;
	else if (colors == 1)
		f->color = 1677216;
	else if (colors == 2)
		f->color = 433216;
	else if (colors == 3)
		f->color = 2377216;
	else if (colors == 4)
		f->color = 677212;
	else if (colors == 5)
		f->color = 37212;
}

int	key_action(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		close_win(f);
	else if (keycode == 'r')
		init_fract(f);
	else if (keycode == 'c')
		change_color(f);
	draw_frac(f);
	return (0);
}
