/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 21:46:51 by gleger            #+#    #+#             */
/*   Updated: 2015/03/05 10:55:34 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *dp)
{
	t_list	*cur;
	t_list	*last;

	cur = dp;
	if (cur)
	{
		dp = dp->next;
		cur->next = NULL;
		while (dp)
		{
			last = cur;
			cur = dp;
			dp = dp->next;
			cur->next = last;
		}
	}
	return (cur);
}
