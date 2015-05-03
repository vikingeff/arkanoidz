/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:17:12 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 15:34:17 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

double		ft_pow(double a, double b)
{
	double	c;
	int		loop;

	c = 1;
	loop = -1;
	while (++loop < b)
		c *= a;
	return (c);
}

double		ft_fact(double x)
{
	double	ret;
	int		loop;

	ret = 1;
	loop = 0;
	while (++loop <= x)
		ret *= loop;
	return (ret);
}

double		ft_sin(double x)
{
	double	y;
	double	s;
	int		loop;

	s = -1;
	y = x;
	loop = 3;
	while (loop <= 100)
	{
		y += s * (ft_pow(x, loop) / ft_fact(loop));
		s *= -1;
		loop += 2;
	}
	return (y);
}

double		ft_cos(double x)
{
	double	y;
	double	s;
	int		loop;

	s = -1;
	y = 1;
	loop = 2;
	while (loop <= 100)
	{
		y += s * (ft_pow(x, loop) / ft_fact(loop));
		s *= -1;
		loop += 2;
	}
	return (y);
}

double		ft_tan(double x)
{
	return (ft_sin(x) / ft_cos(x));
}
