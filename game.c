/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 14:00:50 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 18:24:19 by gleger           ###   ########.fr       */
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
	grid->paddle = 0.0;
	grid->time_pad = 0.5;
	grid->ball = -0.735f;
	grid->irl = grid->ball;
}
