/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:02:55 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/25 22:30:32 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_fractol(t_fractol *fractol, t_complex *z, t_complex *c)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		z->real = c->real;
		z->imaginary = c->imaginary;
		c->real = fractol->j_x;
		c->imaginary = fractol->j_y;
	}
}

void	fractol_data(t_fractol *fractol)
{
	fractol->esc_val = 4;
	fractol->iter_def = 50;
	fractol->offset.real = 0;
	fractol->offset.imaginary = 0;
	fractol->zoom = 1;
	fractol->coloration = 1;
	fractol->start.real = -2;
	fractol->end.real = 2;
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
