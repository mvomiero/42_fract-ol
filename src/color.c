/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:52:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 18:06:12 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	if (f->color_pattern == LUISA)
		set_color_mono(f, f->color);
	if (f->color_pattern == BIANCA)
		set_color_bianca(f, (int [4]){COLOR_8, 0x000000}, 7);
	else if (f->color_pattern == PAOLA)
		set_color_multiple(f, (int [4]){COLOR_1, COLOR_2, COLOR_3, COLOR_4}, 4);
	else if (f->color_pattern == RANDOM)
		set_color_math(f, f->color);
	else
		return ;
}
