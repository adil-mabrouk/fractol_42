/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:33:32 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/27 01:09:25 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_fun(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		if (button == ZOOM_IN)
			fractol->zoom *= 0.8;
		else
			fractol->zoom *= 1.2;
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
	if (keycode == ENTER)
		fractol_data(fractol);
	else if (keycode == PLUS)
		fractol->iter_def += 10;
	else if (keycode == MINUS)
		fractol->iter_def -= 10;
	else if (keycode == ESC)
		ft_close_window(fractol);
	fractol_render(fractol);
	return (0);
}

void	fractol_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 2, 0, key_fun, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_close_window, fractol);
	mlx_hook(fractol->mlx_window, 4, 0, mouse_fun, fractol);
}
