/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:18:42 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 19:11:18 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_set(t_fractol *f, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		f->set = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6))
		f->set = JULIA;
	else
		clean_exit(EXIT_FAILURE, f);
}

static void	get_julia_init_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->cr = -0.766667;
		f->ci = -0.090000;
		return ;
	}
	if (ac == 3)
		clean_exit(EXIT_FAILURE, f);
	if (!ft_strchr(av[2], '.') || !ft_strchr(av[3], '.'))
		clean_exit(EXIT_FAILURE, f);
	f->cr = ft_atof(av[2]);
	f->ci = ft_atof(av[3]);
	if (f->cr > 2.0 || f->cr < -2.0)
		clean_exit(EXIT_FAILURE, f);
	if (f->ci >= 2.0 || f->ci <= -2.0)
		clean_exit(EXIT_FAILURE, f);
}

void	parse_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		clean_exit(EXIT_FAILURE, f);
	else if (f->set == JULIA && ac > 5)
		clean_exit(EXIT_FAILURE, f);
	get_julia_init_values(f, ac, av);
}
