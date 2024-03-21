/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:33:51 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/20 22:19:28 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	to_scale(double unscaled_num, double new_min,
			double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_cplx(t_complex cplx1, t_complex cplx2)
{
	t_complex	sum;

	sum.reel = cplx1.reel + cplx2.reel;
	sum.imaginary = cplx1.imaginary + cplx2.imaginary;
	return (sum);
}

t_complex	power_cplx(t_complex cplx)
{
	t_complex res;

	res.reel = (cplx.reel * cplx.reel) - (cplx.imaginary * cplx.imaginary);
	res.imaginary = 2 * cplx.reel * cplx.imaginary;
	return (res);
}
