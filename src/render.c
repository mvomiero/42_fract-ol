/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:51:19 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:10:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_pixel_color:
	modifies the pixel color directly in the buf corresponding to the image.
	An pixel corresponds to the size of an integer (4 bytes - 32 bits).
	Every color channel corresponds to a char (1 byte - 8 bits) ranging so from 
	00 to FF if expressed in hex. 
	Pixel color expressed as an integer in hex: 0xTTRRGGBB (T = transparency)
	With the bit shifting you access the four different channels of the color
	passed as parameter to the function. 
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
 */
static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->buf[x * 4 + y * WIDTH * 4] = color;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

/* calculate_fractal:
	passes the number to the fractal formula and returns the number of 
	iterations
 */
static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(f, pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	return (nb_iter);
}

/* render:
	converts the pixel real and imaginary (x, y) coordinates into complex 
	numbers (made of pr and pi). The conversion is made thanks the proportion 
	between the extremes of the complex plane corresponding to the current
	window size and the size of the window.
	The color is then set for every pixel-complex
	number and the image rendered to the window.
 */
void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			if (nb_iter > f->iterations - 1)
				set_pixel_color(f, x, y, f->color_foreground);
			else
				set_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
