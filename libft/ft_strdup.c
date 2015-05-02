/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:53 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:52:51 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (s1)
	{
		s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
		if (s2)
		{
			ft_strcpy(s2, s1);
			return (s2);
		}
	}
	return (NULL);
}
