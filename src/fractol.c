/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:08 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/21 18:01:54 by mvomiero         ###   ########.fr       */
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
}

