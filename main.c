/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 08:32:52 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 15:39:43 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static void error_callback(int error, const char* description)
{
	(void)error;
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if ((key == GLFW_KEY_A || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key ==GLFW_KEY_LEFT)
		ft_putendl("LEFT");
	if (key ==GLFW_KEY_RIGHT)
		ft_putendl("RIGHT");
	if (key ==GLFW_KEY_UP)
		ft_putendl("UP");
	if (key ==GLFW_KEY_DOWN)
		ft_putendl("DOWN");

}

static void	printinit(char *r, char *v)
{
	ft_putstr(GREEN);
	ft_putstr("Starting GLFW: ");
	ft_putstr(RED);
	ft_putendl((char *)glfwGetVersionString());
	ft_putstr(GREEN);
	ft_putstr("Renderer: ");
	ft_putstr(RED);
	ft_putendl(r);
	ft_putstr(GREEN);
	ft_putstr("OpenGL version: ");
	ft_putstr(RED);
	ft_putendl(v);
	ft_putstr(NC);
}

int			main(int argc, char **argv)
{
	t_game		game;
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	float start=0.0;
	float end=-0.75;

	if (argc == 1)
		printf ("%s\n",argv[0]);
	
	if (!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(800, 600, "Arkanoid 3000 (C) VikingZ", NULL, NULL);
	initgame(&game);
	
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	printinit((char *)glGetString(GL_RENDERER), (char *)glGetString(GL_VERSION));
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		// glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		// glBegin(GL_TRIANGLES);
		// glColor3f(1.f, 0.f, 0.f);
		// glVertex3f(-0.6f, -0.4f, 0.f);
		// glColor3f(0.f, 1.f, 0.f);
		// glVertex3f(0.6f, -0.4f, 0.f);
		// glColor3f(0.f, 0.f, 1.f);
		// glVertex3f(0.f, 0.6f, 0.f);
		// glEnd();
		if (end < 100)
		{
			start = (float) glfwGetTime() * 0.5f;
			end+=start;
			printf ("%f - %f\n",start,end);
			glTranslatef(0.0f, start, 0.0f);
		}
		else
		{
			glTranslatef(0.0f, (float) glfwGetTime() * -0.25f, 0.0f);
		}
		glColor3f(1.0f, 1.0f, 1.0f);
		drawcircle(0.0f,-0.75f,0.015f,10);
		glPopMatrix();
		//drawsquare(0.0f, 0.0f, 1.0f);
		drawmap();
		drawpaddle();
		// glBegin(GL_LINES);
		// glColor3f(1.0f, 0.0f, 0.0f);
		// glVertex2f(-1.0f, -1.0f);
		// glVertex2f(1.0f, 1.0f);
		// glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
