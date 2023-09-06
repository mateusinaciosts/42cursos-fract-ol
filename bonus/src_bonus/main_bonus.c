/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:03:24 by matsanto          #+#    #+#             */
/*   Updated: 2023/09/05 22:08:40 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"

void	error_message(void)
{
	write(1, "\nbonus\n", 7);
	write(1, "\nThis program renders 2 types of fractal set, ", 46);
	write(1, "you need to choose one of them.\n", 33);
	write(1, "\nOptions available: \n", 22);
	write(1, "\tmandelbrot\n\tjulia parameter1 parameter2\n\n", 43);
	write(1, "Exemples: \n", 12);
	write(1, "\t$./fractol mandelbrot\n", 24);
	write(1, "\t$./fractol julia 0.4 -0.6\n\n", 29);
}

int	check_flag(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp("mandelbrot", argv[1], 11) == 0)
	{
		f->fract_type = 1;
		return (1);
	}
	else if (argc == 4 && ft_strncmp("julia", argv[1], 6) == 0
		&& parse_double(argv[2]) >= -2.0 && parse_double(argv[2]) <= 2.0
		&& parse_double(argv[3]) >= -2.0 && parse_double(argv[3]) <= 2.0
		&& check_double(argv[2]) && check_double(argv[3]))
	{
		f->fract_type = 2;
		f->real_argument = parse_double(argv[2]);
		f->imaginary_argument = parse_double(argv[3]);
		return (1);
	}
	else
		error_message();
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!check_flag(&f, argc, argv))
	{
		exit(0);
	}
	init_mlx(&f);
	return (0);
}
