/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:47:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/28 12:59:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// look at the manual, mlx_loop, you get a function
// -> key_hook(int keycode,void *param);

static int	key_event_extend(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else
		return (1);
	get_complex_layout(mlx);
	render(mlx);
	return (0);
}

/* zoom:
	resizes the window getting new max and min values for both 
	real (x) and immaginary (y) numbers.
	It gets first the range of the two numbers, then multiplicate
	it by the zoom factor, then finds the new coordinates of the 
	new zoomed frame.
	the zoom factor has to be 1/zoom because it goes inverted respect 
	to the image: we want a bigger image -> frame has to be reduced
 */
static void	zoom(t_fractol *f, double zoom)
{
	double	range_r;
	double	range_i;
	double	range_zoomed_r;
	double	range_zoomed_i;
	double	zoom_factor;

	zoom_factor = 1 / zoom;

	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	range_zoomed_r = range_r * zoom_factor;
	range_zoomed_i = range_i * zoom_factor;

	printf("\n cen_r: %f, cen_i: %f\n", range_r, range_i);
	f->max_r = f->max_r - (range_r - range_zoomed_r) / 2;
	f->min_r = f->max_r - range_zoomed_r;
	f->max_i = f->max_i - (range_i - range_zoomed_i) / 2;
	f->min_i = f->max_i - range_zoomed_i;
	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
}

int	key_event(int keycode, t_fractol *mlx)
{
	printf("\n%d\n", keycode);
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
	{
		mlx->iterations += 20;
		reinit_img(mlx);
		color_shift(mlx);
	}

	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == KEY_E)
		get_complex_layout(mlx);
	/* else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R'); */
	else if (keycode == KEY_P)
	{
		mlx->color_pattern = PAOLA;
		color_shift(mlx);
	}
	else if (keycode == KEY_R)
	{
		mlx->color_pattern = RANDOM;
		color_shift(mlx);
	}
	else if (!key_event_extend(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
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
/* mouse_event:
	handels the zoom in and out, with the mouse
	- to zoom in: calls the zoom function first, the move function after
	To call the move function in the right way, it has to make a comparison
	between where the position of mouse is (x,y) in the current image and 
	the position in the new window. It calculates then the move_factor you will
	pass as argument to the move functon.
	move_x corresponds to the scaled value of x in the new resized 
	(scaled) image. It is a factor is passed to the move function, where it 
	is multiplied in order to get the new values of max_r min_r
 */
int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	double	move_x;
	double	move_y;
	double	zoom_factor;
	
	printf("\n%d\n", keycode);
	if (keycode == MOUSE_WHEEL_UP)
	{
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
	}
	else if (keycode == MOUSE_BTN)
	{
		mlx->kr = mlx->min_r + (double)x * (mlx->max_r - mlx->min_r) / WIDTH;
		mlx->ki = mlx->max_i + (double)y * (mlx->min_i - mlx->max_i) / HEIGHT;
		mlx->set = JULIA;
		get_complex_layout(mlx);
		reinit_img(mlx);
		color_shift(mlx);
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 0.5);
	else
		return (0);
	render(mlx);
	return (0);
}