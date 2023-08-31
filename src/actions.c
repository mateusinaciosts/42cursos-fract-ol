
#include "../include/fractol.h"

int	zoom_interaction(int key, t_fractol *f)
{
    if (key == 4)
    {
        double zoom_factor = 0.1;

        f->min_re -= (f->max_re - f->min_re) * zoom_factor;
        f->max_re += (f->max_re - f->min_re) * zoom_factor;
        f->min_im -= (f->max_im - f->min_im) * zoom_factor;
        f->max_im += (f->max_im - f->min_im) * zoom_factor;
    }
    else if (key == 5)
    {
        double zoom_factor = 0.1;

        f->min_re += (f->max_re - f->min_re) * zoom_factor;
        f->max_re -= (f->max_re - f->min_re) * zoom_factor;
        f->min_im += (f->max_im - f->min_im) * zoom_factor;
        f->max_im -= (f->max_im - f->min_im) * zoom_factor;
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
	else if (keycode == 'a')
		f->it_max += 50;
	else if (keycode == 'd')
		f->it_max -= 50;
	else if (keycode == 'r')
		init_fract(f);
	else if (keycode == 'c')
		change_color(f);
	draw_frac(f);
	return (0);
}

