/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:07:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/28 19:09:59 by mvomiero         ###   ########.fr       */
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
	f->cr = 0;
	f->ci = 0;
	f->palette = NULL;
	f->color_pattern = LUISA;
	f->color = 0;
	f->iterations = ITERATIONS;
}

static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((f->iterations + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(err_msg("error initializing color scheme.", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(err_msg("image creation error.", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	reinit_img(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
		if (!f->mlx)
		clean_exit(err_msg("mlx: no mlx_init", 3), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
		if (!f->win)
		clean_exit(err_msg("mlx: no window", 4), f);
	get_complex_layout(f);
	reinit_img(f);
	//color_shift(f);
}

void	get_complex_layout(t_fractol *f)
{
		f->min_r = -2.0;
		f->max_r = 2.0;

		//f->min_i = -2.0;
		//f->max_i = 2;
		f->max_i = ((f->max_r - f->min_r) * HEIGHT / WIDTH) / 2;
		f->min_i = - f->max_i;
		printf("\nmin_i %f, max_i %f\n", f->min_i, f->max_i);
}