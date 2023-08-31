#include "../include/fractol.h"

void mlx_win_init(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGTH, "Fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGTH);
	f->img_ptr = mlx_get_data_addr(f->img, &f->bpp, &f->sl, &f->endian);
}

void init_fract(t_fractol *f)
{
	if (f->fract == 1)
		mandelbrot_init(f);
	else if (f->fract == 2)
		julia_init(f);
}

int draw_frac(t_fractol *f)
{
	if (f->fract == 1)
		mandelbrot(f);
	else if (f->fract == 2)
		julia(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}

void init_mlx(t_fractol *f)
{
	mlx_win_init(f);
	init_fract(f);

	// funcao da mlx:
	mlx_loop_hook(f->mlx, draw_frac, f);
	mlx_hook(f->win, 17, 0L, close_win, f);
	mlx_key_hook(f->win, key_action, f);
	mlx_hook(f->win, 4, 1L << 2, zoom_interaction, f);
	mlx_loop(f->mlx);
}