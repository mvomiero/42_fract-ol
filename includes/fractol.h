/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:16:46 by mvomiero          #+#    #+#             */
/*   Updated: 2023/02/24 13:25:51 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
// for the keys definitions I could have included those ones
//# include <X11/keysym.h>
//# include <X11/X.h>
# include "libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900


# define MAX_ITERATIONS 50

// Fractal sets
# define MANDELBROT 1
# define JULIA 2

//colors
# define LUISA 1
# define PAOLA 2

# define COLOR 0xBA7CF0

# define COLOR_1 0x000000
# define COLOR_2 0xDB23B3
# define COLOR_3 0xFA8378
# define COLOR_4 0xFFFFFF



// struct with all the data
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
	double	kr;
	double	ki;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;

void	init_struct(t_fractol *f);


double	ft_atof(char *str);
void	parse_args(t_fractol *f, int ac, char **av);

void	init(t_fractol *f);
void	render(t_fractol *f);

void	get_complex_layout(t_fractol *f);


int	mandelbrot(double cr, double ci);
void	reinit_img(t_fractol *f);


void	color_shift(t_fractol *f);

void	set_color_mono(t_fractol *f, int color);

void	set_color_multiple(t_fractol *f, int colors[4], int n);



void	help_msg(t_fractol *f);
int		err_msg(char *str1, int errno);


void	move(t_fractol *f, double distance, char direction);

int	key_event(int keycode, t_fractol *mlx);
//static int	key_event_extend(int keycode, t_fractol *mlx);
int	mouse_event(int keycode, int x, int y, t_fractol *mlx);



void	clean_exit(int exit_code, t_fractol *f);

int	end_fractol(t_fractol *mlx);

int	create_trgb(int t, int r, int g, int b);
void	render_background(t_fractol *f, int color);





#endif
