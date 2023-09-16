/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:38 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/09 14:32:42 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

int	zoom_interaction(int key, int x, int y, t_fractol *f)
{
	x = 1;
	y = 1;
	if (key == 4 && x)
	{
		f->min_real -= f->min_real * 0.1;
		f->max_real -= f->max_real * 0.1;
		f->min_imaginary -= f->min_imaginary * 0.1;
		f->max_imaginary -= f->max_imaginary * 0.1;
	}
	if (key == 5 && y)
	{
		f->min_real += f->min_real * 0.1;
		f->max_real += f->max_real * 0.1;
		f->min_imaginary += f->min_imaginary * 0.1;
		f->max_imaginary += f->max_imaginary * 0.1;
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

void	update_position(int keycode, t_fractol *f)
{
	long double	middle_i;
	long double	middle_r;

	middle_i = f->max_imaginary - f->min_imaginary;
	middle_r = f->max_real - f->min_real;
	if (keycode == XK_Up)
	{
		f->min_imaginary -= middle_i * 0.125;
		f->max_imaginary -= middle_i * 0.125;
	}
	if (keycode == XK_Down)
	{
		f->min_imaginary += middle_i * 0.125;
		f->max_imaginary += middle_i * 0.125;
	}
	if (keycode == XK_Left)
	{
		f->min_real -= middle_r * 0.125;
		f->max_real -= middle_r * 0.125;
	}
	if (keycode == XK_Right)
	{
		f->min_real += middle_r * 0.125;
		f->max_real += middle_r * 0.125;
	}
}

int	key_action(int keycode, t_fractol *f)
{
	update_position(keycode, f);
	if (keycode == 65307)
		close_win(f);
	else if (keycode == 'r')
		init_fract(f);
	else if (keycode == 'c')
		change_color(f);
	draw_fract(f);
	return (0);
}
