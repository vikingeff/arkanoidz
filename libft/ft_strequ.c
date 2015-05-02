/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:28:14 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:52:46 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if ((s1 != NULL && s2 != NULL))
	{
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0' && s2[i] == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}