/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:02:55 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/22 03:06:14 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_data(t_fractol *fractol)
{
	fractol->escaped_value = 4;
	fractol->iter_def = 100;
	fractol->offset.reel = 0;
	fractol->offset.imaginary = 0;
	fractol->zoom = 1;
	fractol->coloration = 1;
	fractol->start.reel = -2;
	fractol->end.reel = 2;
	fractol->start.imaginary = 2;
	fractol->end.imaginary = -2;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(2, s++, 1);
}
