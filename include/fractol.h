/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:55 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/05 18:27:20 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//PARAMS DEFINE
# define HEIGHT 800
# define WIDTH 800

//LIBRARIES INCLUDE
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h" 

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
	double	max_im;
	double	min_im;
	double	max_re;
	double	min_re;
}	t_fractol;

int		zoom_interaction(int key, int x, int y, t_fractol *f);
void	change_color(t_fractol *f);
int		key_action(int keycode, t_fractol *f);
int		check_arg(t_fractol *f, int argc, char **argv);
void	init_mlx(t_fractol	*f);
void	init_fract(t_fractol *f);
double	parse_double(const char *str);
int		close_win(t_fractol *f);
void	set_pixel_color(t_fractol *f, int x, int y, int color);
int		check_double(const char *str);
void	mandelbrot_init(t_fractol *f);
int		calculate_mandelbrot(t_fractol *f, double x, double y);
void	window_mandelbrot(t_fractol *f);
int		check_julia(int argc, char **argv, t_fractol *f);
void	julia_init(t_fractol *f);
int		calculate_julia(t_fractol *f, double x, double y);
void	window_julia(t_fractol *f);
int		draw_fract(t_fractol *f);
void	mlx_win_init(t_fractol *f);
int		main(int argc, char **argv);

#endif
