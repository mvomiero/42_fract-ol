/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:39:22 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 16:56:09 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (c);
	return (0);
}

/* skip_space_sign:
	is the first part of the ft_atof(). It wasn't fitting for moulinette
 */
static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '+')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (!av[i])
		return (1);
	if (av[i] == '.')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

/* ft_atof:
	from ascii to float (double).
	Same as atoi, just you have to divide the rational and irrational part.
 */
double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (nb * is_neg);
}

/* 

// ****** JUST RANDOM STUFF DONE AT THE BEGINNING TO TEST MLX LIBRARY

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