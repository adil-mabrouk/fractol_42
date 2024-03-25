/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:33:32 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/25 16:04:57 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_fun(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;

	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		mouse_x = to_scale(x, fractol->start.real, fractol->end.real, WIDTH);
		mouse_y = to_scale(y, fractol->start.imaginary,
				fractol->end.imaginary, HEIGHT);
		if (button == ZOOM_IN)
			zoom = 0.8;
		else
			zoom = 1.2;
		fractol->zoom *= zoom;
		fractol->start.real = mouse_x - (mouse_x - fractol->start.real) * zoom;
		fractol->end.real = mouse_x + (fractol->end.real - mouse_x) * zoom;
		fractol->start.imaginary = mouse_y
			- (mouse_y - fractol->start.imaginary) * zoom;
		fractol->end.imaginary = mouse_y
			+ (fractol->end.imaginary - mouse_y) * zoom;
	}
	fractol_render(fractol);
	return (0);
}

int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_fun(int keycode, t_fractol *fractol)
{
	if (keycode == SHIFT_RIGHT)
		fractol->offset.real += 0.3 * fractol->zoom;
	else if (keycode == SHIFT_LEFT)
		fractol->offset.real -= 0.3 * fractol->zoom;
	else if (keycode == SHIFT_UP)
		fractol->offset.imaginary += 0.3 * fractol->zoom;
	else if (keycode == SHIFT_DOWN)
		fractol->offset.imaginary -= 0.3 * fractol->zoom;
	else if (keycode == ENTER)
		fractol_data(fractol);
	else if (keycode == PLUS)
		fractol->iter_def += 10;
	else if (keycode == MINUS)
		fractol->iter_def -= 10;
	else if (keycode == ESC)
		ft_close_window(fractol);
	else if (keycode == SPACE)
		fractol->coloration += 2;
	fractol_render(fractol);
	return (0);
}

void	fractol_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 2, 0, key_fun, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_close_window, fractol);
	mlx_hook(fractol->mlx_window, 4, 0, mouse_fun, fractol);
}
