/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:03 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:52:24 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "libft.h"

static char		*ft_free(char *res, char *s1, char *s2, int opt)
{
	printf("adresse s1= %p, s2 =%p\n", s1, s2);
	if (opt == 1)
		free(s1);
	else if (opt == 2)
		free(s2);
	else if (opt == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}

char			*ft_strjoin_free(char *s1, char *s2, int opt)
{
	size_t	len;
	char	*dest;

	dest = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			dest = ft_strcpy(dest, s1);
			dest = ft_strcat(dest, s2);
		}
	}
	else if (s1)
		return (ft_free(ft_strdup(s1), s1, s2, opt));
	else if (s2)
		return (ft_free(ft_strdup(s2), s1, s2, opt));
	return (ft_free(dest, s1, s2, opt));
}
