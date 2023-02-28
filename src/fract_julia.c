/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:05:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/28 18:34:07 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < f->iterations)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ci;
		zr = zr * zr - zi * zi + f->cr;
		zi = tmp;
		n++;
	}
	return (n);
}

/* julia:
	the formula is the same as the mandelbrot set.
	The difference is that here we input the z values (c is the constant in the 
	julia set).
 */