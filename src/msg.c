/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:02:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/21 18:02:20 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("\n**********************", 1);
	ft_putendl_fd("      fract'ol      ", 1);
	ft_putendl_fd("\n**********************", 1);
	//print_fractal_options();
	//print_color_options();
	clean_exit(EXIT_FAILURE, f);
}