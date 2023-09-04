/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateus <mateus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:24 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/04 00:47:22 by mateus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_message(void)
{
	write(1, "This program renders 2 types of fractal set, ", 46);
	write(1, "you need to choose one of them.\n", 33);
	write(1, "\nOptions available: \n", 22);
	write(1, "\tMandelbrot\n\tJulia parameter1 parameter2\n\n", 43);
	write(1, "Exemples: \n", 12);
	write(1, "\t$./fractol mandelbrot\n", 24);
	write(1, "\t$./fractol julia 0.4 -0.6\n\n", 29);
	write(1, "Keyboard Shotcuts:\n", 20);
	write(1, "Q - Iterations Out\t'-' Zoom Out\n", 33);
	write(1, "E - Iteration In\t'+' Zoom In\n", 30);
}

int	check_flag(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp("mandelbrot", argv[1], 11) == 0)
	{
		f->fract = 1;
		return (1);
	}
	else if (argc == 4 && ft_strncmp("julia", argv[1], 6) == 0
		&& parse_double(argv[2]) >= -2.0 && parse_double(argv[2]) <= 2.0
		&& parse_double(argv[3]) >= -2.0 && parse_double(argv[3]) <= 2.0
		&& check_double(argv[2]) && check_double(argv[3]))
	{
		f->fract = 2;
		f->arg_re = parse_double(argv[2]);
		f->arg_im = parse_double(argv[3]);
		return (1);
	}
	else
		error_message();
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	f.x = 0;
	f.y = 0;
	if (!check_flag(&f, argc, argv))
	{
		exit(0);
	}
	init_mlx(&f);
	return (0);
}
