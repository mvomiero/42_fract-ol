/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:02:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/01 19:12:55 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instructions(void)
{
	ft_putendl_fd("\n\t\033[35;1m~~~~~~~~\033[0m", 1);
	ft_putendl_fd("\t\033[35;1mFract'ol\033[0m", 1);
	ft_putendl_fd("\t\033[35;1m~~~~~~~~\033[0m", 1);
	ft_putendl_fd("\n\033[35;1;3mFractal sets\033[0m", 1);
	ft_putendl_fd("mandelbrot (M), julia (J)", 1);
	ft_putendl_fd("\n\033[35;1;3mColor sets\033[0m", 1);
	ft_putendl_fd("luisa (L)(1-10), paola (P), random (R)", 1);
	ft_putendl_fd("\n\033[35;1;3mInstructions\033[0m", 1);
	ft_putendl_fd("mouse wheel -> zoom", 1);
	ft_putendl_fd("mouse click -> open julia with mandelbrot values", 1);
	ft_putendl_fd("E -> zoom reset", 1);
	ft_putendl_fd("+ -> iterations +10", 1);
	ft_putendl_fd("- -> iterations -10\n", 1);
}

int	err_msg(char *str1, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	return (errno);
}
