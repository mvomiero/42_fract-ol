/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:55:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/22 17:56:58 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}