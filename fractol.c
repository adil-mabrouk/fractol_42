/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:21:52 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/22 03:39:44 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		exit(EXIT_FAILURE);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
	if (!fractol->mlx_window)
		exit(EXIT_FAILURE);
	fractol->img.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		exit(EXIT_FAILURE);
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel,
											&fractol->img.line_lenght, &fractol->img.endian);
	fractol_data(fractol);
}

void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			n_of_iterations;

	n_of_iterations = 0;
	z.reel = 0;
	z.imaginary = 0;
	c.reel = to_scale(x, fractol->start.reel, fractol->end.reel,
						WIDTH) + fractol->offset.reel;
	c.imaginary = to_scale(y, fractol->start.imaginary, fractol->end.imaginary,
						HEIGHT) + fractol->offset.imaginary;
	while (n_of_iterations < fractol->iter_def)
	{
		z = sum_cplx(power_cplx(z), c);
		if ((z.reel * z.reel) + (z.imaginary * z.imaginary) > fractol->escaped_value)
		{
			color = create_trgb(fractol, n_of_iterations);
			ft_put_pixel(x, y, &fractol->img, color);
			return ;
		}
		n_of_iterations++;
	}
	ft_put_pixel(x, y, &fractol->img, 0);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
			handel_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img,
							0, 0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	if ((ac == 4 && !ft_strcmp(av[1], "julia"))
		|| (ac == 2 && !ft_strcmp(av[1], "mandelbrot")))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		fractol_render(&fractol);
		fractol_events(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr(ERROR_MAEESAGE);
		exit(EXIT_FAILURE);
	}
}
