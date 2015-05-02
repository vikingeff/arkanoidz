/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:52 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:54:46 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_c		*init_couple(void)
{
	t_c			*tab;

	tab = (t_c *)malloc(sizeof(t_c) * 9);
	tab[0].c = 'd';
	tab[0].f = &ft_putnbr_pf;
	tab[1].c = 'i';
	tab[1].f = &ft_putnbr_pf;
	tab[2].c = 'c';
	tab[2].f = &ft_putchar_pf;
	tab[3].c = 's';
	tab[3].f = &ft_putstr_pf;
	tab[4].c = 'p';
	tab[4].f = &ft_puthexa_pf;
	tab[5].c = 'o';
	tab[5].f = &ft_putoctal_pf;
	tab[6].c = 'x';
	tab[6].f = &ft_puthexa_min_pf;
	tab[7].c = 'X';
	tab[7].f = &ft_puthexa_max_pf;
	tab[8].c = 'u';
	tab[8].f = &ft_putnbr_u_pf;
	tab[9].c = 'Z';
	tab[9].f = &ft_putz_pf;
	tab[10].c = '\0';
	return (tab);
}

static int		print_format(const char *format, t_c *tab, va_list ap, int *i)
{
	int		nb;

	nb = ft_atoi(&format[*i]);
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	while (tab->c && tab->c != format[*i])
		tab++;
	if (tab->c)
		return (tab->f(ap, nb));
	else if (format[*i] == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else
	{
		ft_putchar('%');
		ft_putchar(format[*i]);
		return (2);
	}
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			res;
	t_c			*tab;
	va_list		ap;

	i = 0;
	res = 0;
	tab = init_couple();
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res = res + print_format(format, tab, ap, &i);
		}
		else
		{
			ft_putchar(format[i]);
			res++;
		}
		i++;
	}
	va_end(ap);
	return (res);
}
