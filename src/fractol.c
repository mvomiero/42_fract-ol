/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:08 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/22 18:23:28 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* main:
	main function.
 */
int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		help_msg(&f);
	init_struct(&f);
	parse_args(&f, ac, av);
	init(&f);
	render(&f);
	mlx_loop(f.mlx);
}

