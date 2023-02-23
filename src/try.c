/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:15:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/23 17:26:26 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int	main(void)
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
} */


/* // to use a whatever key to close the opened window

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
} */

// TO PRINT A STRING
//mlx_string_put(f.mlx, f.win, 50, 50, -1654654232, "ciaociao");