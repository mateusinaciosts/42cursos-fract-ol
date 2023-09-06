/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:55 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/06 20:26:13 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

//PARAMS DEFINE
# define HEIGHT 800
# define WIDTH 800

//LIBRARIES INCLUDE
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h" 

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_ptr;
	int		endian;
	int		sl;
	int		bits_pixel;
	int		fract_type;
	int		color;
	int		max_iterations;
	double	real_argument;
	double	imaginary_argument;
	double	max_imaginary;
	double	min_imaginary;
	double	max_real;
	double	min_real;
}	t_fractol;

void	mlx_win_init(t_fractol *f);
void	init_mlx(t_fractol	*f);
void	init_fract(t_fractol *f);
int		draw_fract(t_fractol *f);
int		close_win(t_fractol *f);
void	set_pixel_color(t_fractol *f, int x, int y, int color);
int		check_flag(t_fractol *f, int argc, char **argv);
int		check_double(const char *str);
double	parse_double(const char *str);
int		zoom_interaction(int key, int x, int y, t_fractol *f);
void	change_color(t_fractol *f);
int		key_action(int keycode, t_fractol *f);
void	mandelbrot_init(t_fractol *f);
void	window_mandelbrot(t_fractol *f);
int		calculate_mandelbrot(t_fractol *f, double x, double y);
void	julia_init(t_fractol *f);
void	window_julia(t_fractol *f);
int		calculate_julia(t_fractol *f, double x, double y);
void	tricorn_init(t_fractol *f);
void	window_tricorn(t_fractol *f);
int		calculate_tricorn(t_fractol *f, double const_real, double const_imag);
int		update_position(int keycode, t_fractol *fract);

#endif
