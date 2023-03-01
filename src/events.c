/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:47:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 11:33:09 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// look at the manual, mlx_loop, you get a function
// -> key_hook(int keycode,void *param);

static int	key_event_sets(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else
		return (1);
	get_layout(mlx);
	render(mlx);
	return (0);
}

static int	key_event_colors(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_P)
	{
		mlx->color_pattern = PAOLA;
		color_shift(mlx);
	}
	else if (keycode == KEY_R)
	{
		mlx->color_pattern = RANDOM;
		color_shift(mlx);
	}
	render(mlx);
	return (0);
}

int	key_event(int keycode, t_fractol *mlx)
{
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
		get_layout(mlx);
	else if (!key_event_sets(keycode, mlx))
		return (1);
	else if (!key_event_colors(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	printf("\n%d\n", keycode);
	if (keycode == MOUSE_WHEEL_UP)
	{
		mouse_zoom(x, y, mlx);
	}
	else if (keycode == MOUSE_BTN)
	{
		mlx->cr = mlx->min_r + (double)x * (mlx->max_r - mlx->min_r) / WIDTH;
		mlx->ci = mlx->max_i + (double)y * (mlx->min_i - mlx->max_i) / HEIGHT;
		mlx->set = JULIA;
		get_layout(mlx);
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
