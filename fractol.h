/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:57:40 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/21 03:57:29 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FRACTOL_H)
#define FRACTOL_H
#define ERROR_MAEESAGE "Please enter :\n\t./fractol mandelbrot\nor\n\t./fractol julia <real_value> <imaginer_value>\n"
#define ERROR_ALLOC "Allocation failed.\n"
#define ERROR_WINDOW "Something wrong in window\n"

#define HEIGHT 800
#define WIDTH 800

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_ZOOM_IN 5
# define MOUSE_ZOOM_OUT 4
# define SPACE 49
# define PLUS 24
# define MINUS 27
# define SHIFT_RIGHT 124
# define SHIFT_LEFT 123
# define SHIFT_UP 126
# define SHIFT_DOWN 125
# define ESC 53
# define ENTER 36

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

typedef	struct s_complex
{
	double	reel;
	double	imaginary;
}				t_complex;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;


typedef struct s_fractol
{
	void		*mlx_connection;
	void		*mlx_window;
	char		*name;
	t_data		img;
	double		escaped_value;
	int			iter_def;
	int			max_iters;
	t_complex	offset;
	
}				t_fractol;


//  int	prototype
void		fractol_init(t_fractol *fractol);

void		fractol_render(t_fractol *fractol);

// string output
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *s);

// math prototype
double		to_scale(double unscaled_num, double new_min, double new_max, double old_max);
void	fractol_data(t_fractol *fractol);
t_complex	sum_cplx(t_complex cplx1, t_complex cplx2);
t_complex	power_cplx(t_complex cplx);

// collor prototype
void		color_pixel(int x, int y, t_data *img, int color);
void		fractol_events(t_fractol *fractol);
int			key_fun(int keycode, t_fractol *fractol);

int		ft_close_window(t_fractol *fractol);

#endif
