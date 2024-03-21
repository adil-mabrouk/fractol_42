/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 03:33:32 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/21 04:02:08 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	exit(EXIT_SUCCESS);
}

int	key_fun(int keycode, t_fractol *fractol)
{
	if (keycode == SPACE)
		fractol->iter_def += 10;
	else if (keycode == SHIFT_RIGHT)
		fractol->offset.reel += 0.5;
	else if (keycode == SHIFT_LEFT)
		fractol->offset.reel -= 0.5;
	else if (keycode == SHIFT_UP)
		fractol->offset.imaginary += 0.5;
	else if (keycode == SHIFT_DOWN)
		fractol->offset.imaginary -= 0.5;
	else if (keycode == ENTER)
		render_from_0(fractol);
	// else if (keycode == PLUS)
	// 	fractol->offset.imaginary -= 0.5;
	// else if (keycode == MINUS)
	// 	fractol->offset.imaginary -= 0.5;
	fractol_render(fractol);
	return (0);
}

void	fractol_events(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, 02, 0, key_fun, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, ft_close_window, fractol);
}
