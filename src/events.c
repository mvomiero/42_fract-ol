/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:47:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/27 17:04:20 by mvomiero         ###   ########.fr       */
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

/* static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);


	center_r = f->min_r - f->max_r;
	//center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	//center_i = f->min_i - f->max_i;
	printf("\n cen_r: %f, cen_i: %f\n", center_r, center_i);
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
} */

/* static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);


	center_r = f->min_r - f->max_r;
	center_i = f->min_i - f->max_i;

	printf("\n cen_r: %f, cen_i: %f\n", center_r, center_i);
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	//f->max_r = f->min_r - zoom * center_r;
	f->min_r = f->max_r + zoom * center_r;
	f->max_i = f->max_i + (center_i - zoom * center_i) / 2;
	f->min_i = f->max_i + zoom * center_i;
	//f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	//f->max_i = f->min_i + zoom * center_i;
	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
} */

static void	zoom(t_fractol *f, double zoom)
{
	double	range_r;
	double	range_i;
	double	range_zoomed_r;
	double	range_zoomed_i;

	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);


	range_r = f->max_r - f->min_r;
	range_i = f->max_i - f->min_i;
	range_zoomed_r = range_r * zoom;
	range_zoomed_i = range_i * zoom;

	printf("\n cen_r: %f, cen_i: %f\n", range_r, range_i);
	f->max_r = f->max_r - (range_r - range_zoomed_r) / 2;
	f->min_r = f->max_r - range_zoomed_r;
	f->max_i = f->max_i - (range_i - range_zoomed_i) / 2;
	f->min_i = f->max_i - range_zoomed_i;
	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
}

/* static void	zoom(t_fractol *f, double zoom)
{
	double	center_r;
	double	center_i;

	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);


	center_r = f->min_r - f->max_r;
	center_i = f->min_i - f->max_i;

	printf("\n cen_r: %f, cen_i: %f\n", center_r, center_i);
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	//f->max_r = f->min_r - zoom * center_r;
	f->min_r = f->max_r + zoom * center_r;
	f->max_i = f->max_i + (center_i - zoom * center_i) / 2;
	f->min_i = f->max_i + zoom * center_i;
	//f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	//f->max_i = f->min_i + zoom * center_i;
	printf("\n max_r: %f, min_r: %f, max_i: %f, min_i: %f\n", f->max_r, f->min_r, f->max_i, f->min_i);
} */


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
/* 		free(mlx->palette);
		mlx->palette = ft_calloc((mlx->iterations + 1), sizeof(int));
		if (!(mlx->palette))
			clean_exit(err_msg("error initializing color scheme.", 1), mlx); */
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




void	move(t_fractol *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else
		return (0);
	render(mlx);
	return (0);
}