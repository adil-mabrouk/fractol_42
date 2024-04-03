/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:10:43 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/26 17:48:16 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_put_pixel(int x, int y, t_data *img, int color)
{
	int	offset;

	offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}
