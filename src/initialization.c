/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:07:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/22 18:34:03 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(err_msg("error initializing color scheme.", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(err_msg("image creation error.", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
		if (!f->mlx)
		clean_exit(err_msg("mlx: no mlx_init", 3), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
		if (!f->win)
		clean_exit(err_msg("mlx: no window", 4), f);
	f->sx = 2.0;
	f->rx = 0.5;
	f->fx = 1.0;
	get_complex_layout(f);
	init_img(f);
	//color_shift(f);
}

void	get_complex_layout(t_fractol *f)
{
	if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}