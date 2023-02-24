/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:50:51 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/24 17:57:31 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

void	set_color_mono(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
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
		//color2 = 0xFFFFFF;
		color2 = 0x000000;
		i += j;
	}
	//f->palette[f->iterations -1] = 0;
}

void	set_color_math(t_fractol *f, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < f->iterations)
	{
		j = 0;
		while (j < f->iterations)
		{
			fraction = MATH((double)j);
			f->palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0x000000;
		//color2 = 0x000000;
		i += j;
	}
	//f->palette[f->iterations -1] = 0;
}

void	set_color_multiple(t_fractol *f, int colors[4], int n)
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
	//f->palette[f->iterations - 1] = 0;
}

