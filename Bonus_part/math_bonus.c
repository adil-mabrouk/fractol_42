/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:33:51 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:08 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	create_trgb(t_fractol *f, int iters)
{
	int	red;
	int	green;
	int	blue;

	red = (f->coloration * iters) % 255;
	green = (f->coloration * 3 * iters) % 255;
	blue = (f->coloration * 5 * iters) % 255;
	return (red << 16 | green << 8 | blue);
}

double	to_scale(double unscaled_num, double new_min,
			double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_cplx(t_complex cplx1, t_complex cplx2)
{
	t_complex	sum;

	sum.real = cplx1.real + cplx2.real;
	sum.imaginary = cplx1.imaginary + cplx2.imaginary;
	return (sum);
}

t_complex	power_cplx(t_complex cplx, t_fractol *fractol)
{
	t_complex	res;

	res.real = (cplx.real * cplx.real) - (cplx.imaginary * cplx.imaginary);
	res.imaginary = 2 * cplx.real * cplx.imaginary;
	if (!ft_strcmp(fractol->name, "tricorn"))
		res.imaginary = -2 * cplx.real * cplx.imaginary;
	return (res);
}
