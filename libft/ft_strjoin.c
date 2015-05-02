/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:54 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:52:31 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*dest;

	dest = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			i = 0;
			while (*s1)
				dest[i++] = *s1++;
			while (*s2)
				dest[i++] = *s2++;
			dest[i] = '\0';
		}
	}
	else if (s1)
		return (ft_strdup(s1));
	else if (s2)
		return (ft_strdup(s2));
	return (dest);
}
