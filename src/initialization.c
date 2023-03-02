/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:07:09 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:18:54 by mvomiero         ###   ########.fr       */
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
	f->color = COLOR;
	f->color_foreground = WHITE;
	f->iterations = ITERATIONS;
}

/* init_image:
	initialise the image and the color palette.
	gets the address of the buffer and stores it in f->buf
 */
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

/* reinit_image:
	reinitialises the image
 */
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

/* init:
	initialise the mlx and the window, gets the complex plane and reinit the
	image.
 */
void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(err_msg("mlx: no mlx_init", 3), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (!f->win)
		clean_exit(err_msg("mlx: no window", 4), f);
	get_complex_plane_extremes(f);
	reinit_img(f);
}

/* 
	gets the extremes of the complex plane.
	the limits are set to -2, 2 for the real number axis.
	In order to find the imaginary axis extremes, and have the image centered in
	the window, a proportion with the WIDTH 	and HEIGHT of the real window 
	is made
 */
void	get_complex_plane_extremes(t_fractol *f)
{
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->max_i = ((f->max_r - f->min_r) * HEIGHT / WIDTH) / 2;
	f->min_i = -f->max_i;
}
