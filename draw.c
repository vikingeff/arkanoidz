/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:09:47 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 15:54:30 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void		drawsquare(t_color colors, float index)
{
	float	loop;
	float	end;
	float	size;
	float	padding;

	loop = -0.9;
	end = 0.9;
	size = 0.08;
	padding = 0.02;
	while (loop <= end)
	{
		glBegin(GL_QUADS);
		{
			glColor3f(colors.red, colors.green, colors.blue);
			glVertex2f(loop, index);
			glColor3f(colors.red * .8, colors.green * .8, colors.blue * .8);
			glVertex2f(loop + size, index);
			glColor3f(colors.red * .5, colors.green * .5, colors.blue * .5);
			glVertex2f(loop + size, index - size);
			glColor3f(colors.red * .8, colors.green * .8, colors.blue * .8);
			glVertex2f(loop, index - size);
		}
		loop = loop + size + padding;
	}
	glEnd();
}

void		drawcircle(float cx, float cy, float r, int num_segments)
{
	t_circle	myc;
	int			loop;

	myc.theta = 2 * 3.1415926 / (float)num_segments;
	myc.c = ft_cos(theta);
	myc.x = r;
	myc.y = 0;
	loop = -1;
	glBegin(GL_LINE_LOOP);
	while (++loop < num_segments)
	{
		glVertex2f(myc.x + cx, myc.y + cy);
		myc.t = myc.x;
		myc.x = myc.c * myc.x - myc.s * myc.y;
		myc.y = myc.s * myc.t + myc.c * myc.y;
	}
	glEnd();
}

void		drawmap(void)
{
	INIT_COLOR(line1);
	updatecolors(0.0, 0.0, 1.0, &line1);
	drawsquare(line1, 0.9);
	updatecolors(1.0, 0.0, 0.0, &line1);
	drawsquare(line1, 0.8);
	updatecolors(0.0, 1.0, 0.0, &line1);
	drawsquare(line1, 0.7);
	updatecolors(1.0, 0.57, 0.0, &line1);
	drawsquare(line1, 0.6);
	updatecolors(0.54, 0.02, 0.77, &line1);
	drawsquare(line1, 0.5);
	updatecolors(0.11, 0.75, 0.77, &line1);
	drawsquare(line1, 0.4);
}

void		drawpaddle(void)
{
	glBegin(GL_QUADS);
	{
		glColor3f(0.31, 0.36, 0.36);
		glVertex2f(-0.75, -0.1);
		glColor3f(0.31 * .8, 0.36 * .8, 0.36 * .8);
		glVertex2f(-0.75, 0.1);
		glColor3f(0.31 * .5, 0.36 * .5, 0.36 * .5);
		glVertex2f(-0.85, 0.1);
		glColor3f(0.31 * .8, 0.36 * .8, 0.36 * .8);
		glVertex2f(-0.85, -0.1);
	}
	glEnd();
}
