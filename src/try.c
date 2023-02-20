/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:15:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/20 18:41:00 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	
	// for a simple printing of a rectangle 
	for (int i = WIDTH - 50; i > 50; i--)
	{
		for (int j = HEIGHT - 200; j > 200; j--)
			mlx_pixel_put(mlx, win, i, j, 0xFFFFFF);
		mlx_pixel_put(mlx, win, i, HEIGHT/2, 0xFFFFFF);
	}
  	mlx_loop(mlx);
}