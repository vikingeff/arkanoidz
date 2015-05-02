/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:55 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:51:07 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		while (i <= len / 2)
		{
			tmp = str[i];
			str[i] = str[len - i];
			str[len - i] = tmp;
			i++;
		}
	}
	return (str);
}
