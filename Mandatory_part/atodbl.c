/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:53:35 by amabrouk          #+#    #+#             */
/*   Updated: 2024/03/27 01:58:19 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_err(void)
{
	ft_putstr(ERROR_MAEESAGE);
	exit(EXIT_FAILURE);
}

int	ft_atoi(char **s, int *sign)
{
	int	integer;

	integer = 0;
	if (!**s)
		put_err();
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
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

	(1) && (dbl = 0, power = 1);
	integer = ft_atoi(&s, &sign);
	if (*s == '.')
		s++;
	if (*(s - 1) == '.' && (!*s || *s == ' '))
		put_err();
	while (*s >= '0' && *s <= '9')
	{
		power /= 10;
		dbl = dbl + (*s - '0') * power;
		s++;
	}
	while (*s)
	{
		if (*s != ' ')
			put_err();
		s++;
	}
	return ((integer + dbl) * sign);
}
