/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:31:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 11:33:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* zoom:
	resizes the window getting new max and min values for both 
	real (x) and immaginary (y) numbers.
	It gets first the range of the two numbers, then multiplicate
	it by the zoom factor, then finds the new coordinates of the 
	new zoomed frame.
	the zoom factor has to be 1/zoom because it goes inverted respect 
	to the image: we want a bigger image -> frame has to be reduced
 */
void	zoom(t_fractol *f, double zoom)
{
	double	range_r;
	double	range_i;
	double	range_zoomed_r;
	double	range_zoomed_i;
	double	zoom_factor;

	zoom_factor = 1 / zoom;
	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	range_zoomed_r = range_r * zoom_factor;
	range_zoomed_i = range_i * zoom_factor;
	f->max_r = f->max_r - (range_r - range_zoomed_r) / 2;
	f->min_r = f->max_r - range_zoomed_r;
	f->max_i = f->max_i - (range_i - range_zoomed_i) / 2;
	f->min_i = f->max_i - range_zoomed_i;
}

/* move:
	depending the direction char the function "moves" in the different directions.
	The moving is actually done by shifting the max_ and min_ depending the 
	given move factor calculated int the mouse_event function.
 */
void	move(t_fractol *f, double move_factor, char direction)
{
	double	range_r;
	double	range_i;

	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += range_r * move_factor;
		f->max_r += range_r * move_factor;
	}
	else if (direction == 'L')
	{
		f->min_r -= range_r * move_factor;
		f->max_r -= range_r * move_factor;
	}
	else if (direction == 'D')
	{
		f->min_i -= range_i * move_factor;
		f->max_i -= range_i * move_factor;
	}
	else if (direction == 'U')
	{
		f->min_i += range_i * move_factor;
		f->max_i += range_i * move_factor;
	}
}

/* mouse_zoom:
	first zooms in and gets so new max and min values.
	finds then a factor that represents the absolute distance of the point from 
	the beginning.
	factor_x = x - WIDTH / (zoom_factor) / WIDTH;
	factor_x = x - (center point) / WIDTH;
	factor_x = (general position of x related to the center) / WIDTH;
	factor_x = absolute position of x in a general frame;

	going then to the move function:
	f->min_r += range_r * move_factor;
	f->min_r += range_r * factor_x;
	f->min_r += range_r * absolute position of x in a general frame;
	f->min_r =  min_r + range_r * absolute position of x in a general frame;
	f->min_r =  min_r + relative position of x in the particular new frame;

	so basically we find how distant is in an absolute way the point (x,y) and 
	multiplicate that factor for the new frame value...it will be the value we 
	have to move the frame...that will be of course after the move just centered
 */
int	mouse_zoom(int x, int y, t_fractol *mlx)
{
	double	move_x;
	double	move_y;
	double	zoom_factor;

	zoom_factor = 2;
	zoom(mlx, zoom_factor);
	move_x = ((double)x - WIDTH / (zoom_factor)) / WIDTH;
	move_y = ((double)y - HEIGHT / (zoom_factor)) / HEIGHT;
	if (x < 0)
		move(mlx, -(move_x), 'L');
	else if (x > 0)
		move(mlx, (move_x), 'R');
	if (y < 0)
		move(mlx, -(move_y), 'U');
	else if (y > 0)
		move (mlx, (move_y), 'D');
	return (0);
}
