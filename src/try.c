/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:15:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/20 15:35:41 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;
	//void	*mlx_win;

	mlx = mlx_init();
	//mlx_win = 
	mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}