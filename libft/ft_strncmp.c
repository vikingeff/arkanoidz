/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:54 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:51:45 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2 && n)
	{
		while (n-- > 0)
		{
			if (*s1 != *s2)
			{
				if (*(unsigned char *)s1 > *(unsigned char *)s2)
					return (1);
				else
					return (-1);
			}
			if (*s1 == '\0')
				return (0);
			s1++;
			s2++;
		}
	}
	return (0);
}
