/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/03/02 16:50:17 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// for the keys definitions I could have included those ones
//# include <X11/keysym.h> 		
//# include <X11/X.h>
# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

// Window size
# define WIDTH 600
# define HEIGHT 900

// Iterations
# define ITERATIONS 10
# define ITERATIONS_MAX 800

// Fractal sets
# define MANDELBROT 1
# define JULIA 2

// Color sets
# define LUISA 1
# define PAOLA 2
# define BIANCA 3
# define RANDOM 5

// Colors
# define COLOR 0xFC0FDD

# define COLOR_1 0xF6CC22
# define COLOR_2 0xE03B02
# define COLOR_3 0x8513D4
# define COLOR_4 0xBF2C1F
# define COLOR_5 0x8703FE
# define COLOR_6 0x5350FF
# define COLOR_7 0xE5FE03
# define COLOR_8 0xCC0033
# define COLOR_9 0x000F24
# define WHITE 0xFFFFFF
# define BLACK 0x000000

// Struct with all the data
typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	cr;
	double	ci;
	int		*palette;
	int		color_pattern;
	int		color;
	int		color_foreground;
	int		iterations;
}	t_fractol;

// Instructions
void	print_instructions(void);

// Initiazation
void	init_struct(t_fractol *f);
void	init_mlx(t_fractol *f);
void	get_complex_plane_extremes(t_fractol *f);

// Parsing arguments
double	ft_atof(char *str);
int		arg_is_zero(char *av);
void	parse_args(t_fractol *f, int ac, char **av);

// Fractal calculations
int		mandelbrot(t_fractol *f, double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);

// Rendering
void	reinit_img(t_fractol *f);
void	render(t_fractol *f);

// Colors and color sets
void	color_set(t_fractol *f);
void	set_color_mono(t_fractol *f, int color);
void	set_color_bi(t_fractol *f, int color);
void	set_color_bianca(t_fractol *f, int colors[2], int n);
void	set_color_multiple(t_fractol *f, int colors[3], int n);
void	set_color_math(t_fractol *f, int color);

// Events
void	zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double distance, char direction);
int		key_event(int keycode, t_fractol *mlx);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);
int		mouse_zoom(int x, int y, t_fractol *mlx);

// Exit and Errors
void	clean_exit(int exit_code, t_fractol *f);
int		end_fractol(t_fractol *mlx);
int		err_msg(char *str1, int errno);

// Math variables possibilities
//# define MATH cos
//# define MATH exp
//# define MATH log
//# define MATH sqrt
//# define MATH cos

#endif
