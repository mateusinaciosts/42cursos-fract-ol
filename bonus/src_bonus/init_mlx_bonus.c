/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:32 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/05 22:08:40 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

void	mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img_ptr = mlx_get_data_addr(f->img, &f->bits_pixel, &f->sl, &f->endian);
}

void	init_fract(t_fractol *f)
{
	if (f->fract_type == 1)
		mandelbrot_init(f);
	else if (f->fract_type == 2)
		julia_init(f);
}

int	draw_fract(t_fractol *f)
{
	if (f->fract_type == 1)
		window_mandelbrot(f);
	else if (f->fract_type == 2)
		window_julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

void	init_mlx(t_fractol *f)
{
	mlx_win_init(f);
	init_fract(f);
	mlx_loop_hook(f->mlx, draw_fract, f);
	mlx_hook(f->win, 17, 0L, close_win, f);
	mlx_key_hook(f->win, key_action, f);
	mlx_hook(f->win, 4, 1L << 2, zoom_interaction, f);
	mlx_loop(f->mlx);
}
