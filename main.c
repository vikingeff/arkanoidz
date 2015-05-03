/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 08:32:52 by gleger            #+#    #+#             */
/*   Updated: 2015/05/03 18:43:07 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arkanoid.h>

static	t_game g_game;

static void error_callback(int error, const char *description)
{
	(void)error;
	fputs(description, stderr);
}

static void key_callback(GLFWwindow *window, int key, int scancode,\
	int action, int mods)
{
	(void)scancode;
	(void)mods;
	if ((key == GLFW_KEY_A || key == GLFW_KEY_ESCAPE) && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_LEFT)
		g_game.paddle += -0.05;
	if (key == GLFW_KEY_RIGHT)
		g_game.paddle -= -0.05;
	if (key == GLFW_KEY_UP)
	{
		g_game.ball = g_game.irl;
		g_game.time_pad = -0.35;
	}
	if (key == GLFW_KEY_DOWN)
		ft_putendl("DOWN");
}

static void	printinit(const unsigned char *r, const unsigned char *v)
{
	ft_putstr(GREEN);
	ft_putstr("Starting GLFW: ");
	ft_putstr(RED);
	ft_putendl((char *)glfwGetVersionString());
	ft_putstr(GREEN);
	ft_putstr("Renderer: ");
	ft_putstr(RED);
	ft_putendl((char *)r);
	ft_putstr(GREEN);
	ft_putstr("OpenGL version: ");
	ft_putstr(RED);
	ft_putendl((char *)v);
	ft_putstr(NC);
}

static void	loading(GLFWwindow *win)
{
	float				ratio;
	int					width;
	int					height;

	glfwGetFramebufferSize(win, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	g_game.irl = g_game.ball + (float)glfwGetTime() * g_game.time_pad;
	drawcircle(0.0f + g_game.paddle, g_game.irl, 0.015f, 10);
	glPopMatrix();
	drawmap();
	drawpaddle(g_game.paddle);
	glfwSwapBuffers(win);
	glfwPollEvents();
}

int			main(void)
{
	GLFWwindow			*win;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	win = glfwCreateWindow(800, 600, "Arkanoid 3000 (C) VikingZ", NULL, NULL);
	initgame(&g_game);
	if (!win)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	printinit(glGetString(GL_RENDERER), glGetString(GL_VERSION));
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(win, key_callback);
	while (!glfwWindowShouldClose(win))
	{
		loading(win);
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
