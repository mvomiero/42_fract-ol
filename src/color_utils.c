/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:50:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:41:02 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* interpolate:
	interpolates two pixels. Each color channel is calculate differently,
	thanks to a comparison to white (FF).
	>> 16 -> r; >> 8 -> g; >> 0 -> b;
	Multiplies the range value (end - start) by the fraction to get the same
	proportion and then add the starting value to get the right position.
	Returns at the end thanks to the bitwise operations the different channels
	in a single int value.
 */
static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];
	int	inter_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	inter_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	inter_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	inter_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | inter_rgb[0] << 16 | inter_rgb[1] << 8 | inter_rgb[2]);
}

/* set_color_mono:
	monochromatic color set. It goes from WHITE to WHITE, reaching the color in
	the middle (that's why the second nested loop with iterations / 2) 
 */
void	set_color_mono(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = WHITE;
	color2 = color;
	i = 0;
	while (i < f->iterations)
	{
		j = 0;
		while (j < f->iterations / 2)
		{
			fraction = (double)j / (f->iterations / 2);
			f->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = WHITE;
		i += j;
	}
}

/* set_color_math:
	fraction is determined by a mathematic formula and assigned to it, in this 
	way a "random" effect is created, even if still following the iterations 
	increment.
 */
void	set_color_math(t_fractol *f, int color)
{
	int		i;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < f->iterations)
	{
		fraction = log((double)i);
		f->palette[i] = interpolate(color1, color2, fraction);
		i++;
	}
}

/* set_color_multiple:
	ranges to the different color values of the array. n is the number of colors
	and the chunks the palette is devided into. 
	Iterators: i general iterator, j chunk iterator, x array (colors) iterator.
 */
void	set_color_multiple(t_fractol *f, int colors[3], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < f->iterations)
	{
		j = 0;
		while ((i + j) < f->iterations && j < (f->iterations / (n - 1)))
		{
			fraction = (double)j / (f->iterations / (n - 1));
			f->palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
}

/* set_color_bianca:
	mix of the color_multiple() and the color_mono().
	Generates some stripes in gradients going from one color to the other.
 */
void	set_color_bianca(t_fractol *f, int colors[2], int n)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = colors[0];
	color2 = colors[1];
	i = 0;
	while (i < f->iterations)
	{
		j = 0;
		while ((i + j) < f->iterations && j < (f->iterations / (n - 1)))
		{
			fraction = (double)j / (f->iterations / (n - 1));
			f->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = colors[0];
		color2 = colors[1];
		i += j;
	}
}
