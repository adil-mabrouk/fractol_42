/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:21:52 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/21 03:44:58 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_error(char *message)
{
	ft_putstr(message);
	exit (EXIT_FAILURE);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		put_error(ERROR_ALLOC);
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
	if (!fractol->mlx_window)
		put_error(ERROR_WINDOW);
	fractol->img.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		put_error(ERROR_ALLOC);
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &fractol->img.bits_per_pixel,
											&fractol->img.line_lenght, &fractol->img.endian);
	fractol_data(fractol);
}

void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			color = 0;
	int			n_of_iterations;

	n_of_iterations = 0;
	z.reel = 0;
	z.imaginary = 0;
	c.reel = to_scale(x, -2, +2, WIDTH) + fractol->offset.reel;
	c.imaginary = to_scale(y, +2, -2, HEIGHT) + fractol->offset.imaginary;
	while (n_of_iterations < fractol->iter_def)
	{
		z = sum_cplx(power_cplx(z), c);
		if ((z.reel * z.reel) + (z.imaginary * z.imaginary) > fractol->escaped_value)
		{
			color = to_scale(n_of_iterations, 0x000000, 0xFFFFFF, fractol->iter_def);
			color_pixel(x, y, &fractol->img, color);
			return ;
		}
		n_of_iterations++;
	}
	color_pixel(x, y, &fractol->img, color);
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
		fractol_events(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr(ERROR_MAEESAGE);
		exit(EXIT_FAILURE);
	}
}
