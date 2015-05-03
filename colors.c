/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:18:26 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 15:36:04 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		updatecolors(float r, float g, float b, t_color *pane)
{
	pane->red = r;
	pane->green = g;
	pane->blue = b;
}
