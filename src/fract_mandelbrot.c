/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:55:48 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/28 11:54:53 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* mandelbort:
	calculate if the number (converted from the pixel coordinates)
	is part or not of the mandelbrot set, or better said, after how
	many iterations the number is out of its magnitude, which is 2.
 */
int	mandelbrot(t_fractol *f, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < f->iterations)
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

/* Mandelbrot formula:
	Z(n+1) = Z(n)² + c; -> we can write it semplified
	Z = Z² + c;
	Z = Z * Z + c; -> knowing we speak about real numbers:
	Z = (zr + zi) * (zr + zi) + (cr + ci);
	Z = zr² + zi² + zizr + zrzi + (cr + ci);
	Z = zr² + zi² + 2zizr + (cr + ci);
	Now, knowing that Z = zr + zi, and that the polynomials with i will be
	the imaginary part of the number, we can get the two parts of the complex 
	number
	zr + zi = zr² + zi² + 2zizr + (cr + ci);
	->
	{
		zr = zr² + zi² + cr;
		zi = 2zizrci;
	}
	
	Magnitute:
	we know the maginitude of the mandelbrot set is 2. That means, that all
	numbers greater then 2 will tend to infinity.
	From trigonometry, we know that the absolute value of a complex number 
	corresponds to the square root of the sum of the square built on its compo
	nents. -> 
	Z(absolute value) = √ (zr² + zi²); 
	-> now we need the comparison for the maginitude, an if statement
	√ (zr² + zi²) > 2;
	-> we know from matematics we can multiply by 2 and get rid of sqrt
	(zr² + zi²) > 4;
 */