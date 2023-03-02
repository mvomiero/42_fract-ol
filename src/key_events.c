/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:47:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:18:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* event_sets:
	changes to the different julia or mandelbrot sets
 */
static int	key_event_sets(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_M && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_J && mlx->set != JULIA)
		mlx->set = JULIA;
	else
		return (1);
	get_complex_plane_extremes(mlx);
	render(mlx);
	return (0);
}

/* color_patterns:
	changes to the different color patterns
 */
static int	key_event_color_patterns(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_P)
	{
		mlx->color_foreground = COLOR_1;
		mlx->color_pattern = PAOLA;
	}
	else if (keycode == KEY_R)
		mlx->color_pattern = RANDOM;
	else if (keycode == KEY_L)
	{
		mlx->color_foreground = WHITE;
		mlx->color_pattern = LUISA;
	}
	else if (keycode == KEY_B)
	{
		mlx->color_foreground = COLOR_8;
		mlx->color_pattern = BIANCA;
	}
	else
		return (1);
	color_set(mlx);
	render(mlx);
	return (0);
}

/* colors:
	changes the colors for the LUISA color set, pressing numbers 0-9
 */
static int	key_event_colors(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_1)
		mlx->color = COLOR_1;
	else if (keycode == KEY_2)
		mlx->color = COLOR_2;
	else if (keycode == KEY_3)
		mlx->color = COLOR_3;
	else if (keycode == KEY_4)
		mlx->color = COLOR_4;
	else if (keycode == KEY_5)
		mlx->color = COLOR_5;
	else if (keycode == KEY_6)
		mlx->color = COLOR_6;
	else if (keycode == KEY_7)
		mlx->color = COLOR_7;
	else if (keycode == KEY_8)
		mlx->color = COLOR_8;
	else if (keycode == KEY_9)
		mlx->color = COLOR_9;
	else if (keycode == KEY_0)
		mlx->color = COLOR;
	else
		return (1);
	color_set(mlx);
	render(mlx);
	return (0);
}

/* iterations:
	chil function of key_event.
	sets an higher or lower number of iterations
 */
static int	key_event_iterations(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_PLUS && mlx->iterations < ITERATIONS_MAX)
	{
		mlx->iterations += 10;
		reinit_img(mlx);
		color_set(mlx);
	}
	else if (keycode == KEY_MINUS && (mlx->iterations > 10))
	{
		mlx->iterations -= 10;
		reinit_img(mlx);
		color_set(mlx);
	}
	else
		return (1);
	render(mlx);
	return (0);
}

/* key_event:
	passed to the mlx_key_hook(), gets the parameteter keycode from it.
	(see manual)
	depending form the key pressed, different actions are executed. Due to the 
	amount of the different commands, it is split in thematic smaller child 
	functions
 */
int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_E)
		get_complex_plane_extremes(mlx);
	else if (!key_event_sets(keycode, mlx))
		return (1);
	else if (!key_event_color_patterns(keycode, mlx))
		return (1);
	else if (!key_event_colors(keycode, mlx))
		return (1);
	else if (!key_event_iterations(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
}
