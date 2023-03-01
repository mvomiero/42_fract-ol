/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:02:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 13:22:31 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instructions(void)
{
	//ft_putendl_fd("\n\033[35;1;4mHello\033[0m", 1);
	ft_putendl_fd("\n\033[35;1;4mFract'ol\033[0m", 1);
	ft_putendl_fd("\n\033[35;1;3mFractal sets\033[0m", 1);
	ft_putendl_fd("mandelbrot (M), julia (J)", 1);
	ft_putendl_fd("\n\033[35;1;3mColor sets\033[0m", 1);
	ft_putendl_fd("luisa (L), paola (P), random (R)", 1);
	ft_putendl_fd("\n\033[35;1;3mInstructions\033[0m", 1);
	//ft_putendl_fd("\n\033[35;1mHello\033[0m", 1);
	//ft_putendl_fd("\n\033[35;1mHello\033[0m", 1);
	//print_fractal_options();
	//print_color_options();
}

int	err_msg(char *str1, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	return (errno);
}
