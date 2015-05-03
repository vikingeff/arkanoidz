/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:00:50 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 15:57:37 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		initgame(t_game *grid)
{
	int		loop;
	int		loop2;

	loop = -1;
	loop2 = -1;
	while (++loop < LINES)
	{
		while (++loop2 < ROWS)
			grid->map[loop][loop2] = 0;
		loop2 = -1;
	}
}
