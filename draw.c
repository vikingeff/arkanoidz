/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 13:09:47 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 13:15:37 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

void 	DrawSquare(t_color colors, float var, float buff, float max)
{
  // Draws a square with a gradient color at coordinates 0, 10
	// float var = -0.9f;
	// float buff = 0.08f;
	// float max = 0.9f;
	while (var < max)
	{
		glBegin(GL_QUADS);
		{
			glColor3f(colors.red, colors.green, colors.blue);
			glVertex2f(var, max);
			glColor3f(colors.red * .8, colors.green * .8, colors.blue * .8);
			glVertex2f(buff+var, max);
			glColor3f(colors.red * .5, colors.green * .5, colors.blue * .5);
			glVertex2f(buff+var, max-buff);
			glColor3f(colors.red * .8, colors.green * .8, colors.blue * .8);
			glVertex2f(var, max-buff);
		}
		var=var+buff+0.02;
	}
	glEnd();
}

void 	DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	float theta = 2 * 3.1415926 / (float)num_segments; 
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0; 
    
	glBegin(GL_LINE_LOOP);

	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	} 
	glEnd(); 
}

void	drawmap()
{
	INIT_COLOR(line1);
	line1.blue=1.0;
	DrawSquare(line1, -0.9, 0.08, 0.9);
	line1.blue=0.0;
	line1.red=1.0;
	DrawSquare(line1, -0.8, 0.08, 0.8);
	line1.red=0.0;
	line1.green=1.0;
	DrawSquare(line1, -0.7, 0.08, 0.7);
}