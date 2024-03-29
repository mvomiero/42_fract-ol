/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:08 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 17:49:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* main:
	main function.
 */
int	main(int ac, char **av)
{
	t_fractol	f;

	print_instructions();
	if (ac < 2 || ac > 4)
		exit(1);
	init_struct(&f);
	parse_args(&f, ac, av);
	init_mlx(&f);
	color_set(&f);
	render(&f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
