/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:55 by matsanto          #+#    #+#             */
/*   Updated: 2023/08/31 14:03:56 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

//PARAMS DEFINE
# define HEIGTH 800
# define WIDTH 800
# define MAX_ITER 200

//LIBRARIES INCLUDE
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h" 


typedef struct s_fractol
{
    // Componentes gráficos
    void *mlx;
    void *win;
    void *img;
    void *img_ptr;

    // Informações de imagem
    int endian;
    int sl;
    int bpp;

    // Configurações da fractal
    int fract;
    int color;
    int x;
    int y;
    int y_max;
    int inter;
    int it_max;

    // Parâmetros de visualização
    double zoom;
    double x1;
    double y1;

    // Parâmetros de cálculo
    double arg_re;
    double arg_im;
    double c_r;
    double c_i;
    double z_r;
    double z_i;
    double tmp;

    // Limites da parte imaginária e real
    double max_im;
    double min_im;
    double max_re;
    double min_re;
} t_fractol;


int	zoom_interaction(int key, t_fractol *f);
void	change_color(t_fractol *f);
int	key_action(int keycode, t_fractol *f);

int		check_arg(t_fractol *f, int argc, char **argv);
void init_mlx(t_fractol	*f);
void init_fract(t_fractol *f);

double	parseDouble(const char *str);
int		close_win(t_fractol *f);
void	put_pxl_to_img(t_fractol *f, int x, int y, int color);
int		check_double(const char *str);

void	mandelbrot_init(t_fractol *f);
void	mandelbrot_math(t_fractol *f, double x, double y);
void	mandelbrot(t_fractol *f);

int		check_julia(int argc, char **argv, t_fractol *f);
void	julia_init(t_fractol *f);
void	julia_math(t_fractol *f, double x, double y);
void	*julia(t_fractol *f);


int		draw_frac(t_fractol *f);
void	mlx_win_init(t_fractol *f);
int		main(int argc, char **argv);


#endif
