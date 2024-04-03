/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:57:40 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/27 03:40:55 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FRACTOL_H)
# define FRACTOL_H

# define ERROR_MAEESAGE "\nAvailable Fractals in Mandatory Part :\
\n\n\t./fractol mandelbrot\nor\n\t\
./fractol julia <real_value> <imaginary_value>\n\n"

# define HEIGHT 800
# define WIDTH 800

# define ZOOM_IN 5
# define ZOOM_OUT 4
# define PLUS 24
# define MINUS 27
# define ESC 53
# define ENTER 36

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_complex
{
	double	real;
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
	double		esc_val;
	int			iter_def;
	double		zoom;
	t_complex	start;
	t_complex	end;
	double		j_x;
	double		j_y;
}				t_fractol;

void		fractol_init(t_fractol *fractol);
void		fractol_render(t_fractol *fractol);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr(char *s);
void		if_julia(t_fractol *fractol, t_complex *z, t_complex *c);
double		to_scale(double unscaled_num, double new_min, \
					double new_max, double old_max);
void		fractol_data(t_fractol *fractol);
t_complex	sum_cplx(t_complex cplx1, t_complex cplx2);
t_complex	power_cplx(t_complex cplx);
void		ft_put_pixel(int x, int y, t_data *img, int color);
int			create_trgb(int iters);
void		fractol_events(t_fractol *fractol);
int			key_fun(int keycode, t_fractol *fractol);
int			ft_close_window(t_fractol *fractol);
double		ft_atodbl(char *s, int sign);
int			ft_atoi(char **s, int *sign);

#endif
