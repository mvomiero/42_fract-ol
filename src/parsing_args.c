/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:18:42 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:23:12 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* get_set:
	gets the set from passed as argument av[1] and stores it in the struct
 */
static void	get_set(t_fractol *f, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		f->set = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6))
		f->set = JULIA;
	else
		clean_exit(EXIT_FAILURE, f);
}

/* get_julia_initial_values:
	sets standard values for the julia set, if they are not provided.
	If they are provided, it converts them from ascii to float and stores them
	in the struct.
 */
static void	get_julia_init_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->cr = -0.766667;
		f->ci = -0.090000;
		return ;
	}
	if (ac == 3 || ac > 4)
		clean_exit(EXIT_FAILURE, f);
	f->cr = ft_atof(av[2]);
	f->ci = ft_atof(av[3]);
}

/* parse_args:
	parse the arguments and stores the values in the struct
 */
void	parse_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		clean_exit(EXIT_FAILURE, f);
	else if (f->set == JULIA && ac > 5)
		clean_exit(EXIT_FAILURE, f);
	get_julia_init_values(f, ac, av);
}
