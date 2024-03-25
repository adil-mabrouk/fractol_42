/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:53:35 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/25 15:06:59 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char **s, int *sign)
{
	int	integer;

	integer = 0;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
		{
			*sign = -1;
			(*s)++;
		}
	}
	while (**s >= '0' && **s <= '9')
	{
		integer = integer * 10 + (**s - '0');
		(*s)++;
	}
	return (integer);
}

double	ft_atodbl(char *s, int sign)
{
	int		integer;
	double	power;
	double	dbl;

	dbl = 0;
	power = 1;
	integer = ft_atoi(&s, &sign);
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		power /= 10;
		dbl = dbl + (*s - '0') * power;
		s++;
	}
	while (*s)
	{
		if (*s != ' ')
		{
			write(2, "\tIncompatible arguments\n", 25);
			exit (EXIT_FAILURE);
		}
		s++;
	}
	return ((integer + dbl) * sign);
}
