/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:53 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:53:14 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2)
		{
			if (*s1 == '\0')
				return (0);
			s1++;
			s2++;
		}
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else
			return (-1);
	}
	return (0);
}
