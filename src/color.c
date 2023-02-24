/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:52:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/24 13:08:06 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	if (f->color_pattern == LUISA)
		set_color_mono(f, COLOR);
	else if (f->color_pattern == PAOLA)
		set_color_multiple(f, (int [4]){COLOR_1, COLOR_2, COLOR_3, COLOR_4}, 4);
/* 		set_color_multiple(f, (int [4]){0x000000, alt_color,
			get_percent_color(f->color, 50), 0xFFFFFF}, 4); */
	else
		return ;
	//	color_shift_striped(f);
}