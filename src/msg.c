/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:02:04 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 14:20:38 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
	instructions about how to properly use the program
 */
void	print_instructions(void)
{
	ft_putendl_fd("\n\t\033[35;1m~~~~~~~~\033[0m", 1);
	ft_putendl_fd("\t\033[35;1mFract'ol\033[0m", 1);
	ft_putendl_fd("\t\033[35;1m~~~~~~~~\033[0m", 1);
	ft_putendl_fd("\n\033[35;1;3mFractal sets\033[0m", 1);
	ft_putendl_fd("mandelbrot (M)", 1);
	ft_putendl_fd("julia (J), possible to input values as av[2-3]", 1);
	ft_putendl_fd("\n\033[35;1;3mColor sets\033[0m", 1);
	ft_putendl_fd("luisa (L)(1-10), paola (P), random (R)", 1);
	ft_putendl_fd("\n\033[35;1;3mInstructions\033[0m", 1);
	ft_putendl_fd("mouse wheel -> zoom", 1);
	ft_putendl_fd("mouse click -> open julia with mandelbrot values", 1);
	ft_putendl_fd("E -> zoom reset", 1);
	ft_putendl_fd("+ -> iterations +10", 1);
	ft_putendl_fd("- -> iterations -10\n", 1);
}

/* 
	error message printed.
 */
int	err_msg(char *str1, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	return (errno);
}
