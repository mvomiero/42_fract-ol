/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:52:55 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 18:50:47 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_shift(t_fractol *f)
{
	if (f->color_pattern == LUISA)
		set_color_mono(f, f->color);
	if (f->color_pattern == BIANCA)
		set_color_bianca(f, (int [2]){COLOR_8, COLOR_9}, 7);
	else if (f->color_pattern == PAOLA)
		set_color_multiple(f, (int [3]){COLOR_1, COLOR_2, COLOR_3}, 4);
	else if (f->color_pattern == RANDOM)
		set_color_math(f, f->color);
	else
		return ;
}
