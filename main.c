/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 08:32:52 by gleger            #+#    #+#             */
/*   Updated: 2015/05/02 22:12:21 by gleger           ###   ########.fr       */
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
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	if (argc == 1)
		printf ("%s\n",argv[0]);
	
	if (!glfwInit())
		exit(EXIT_FAILURE);
	
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// glfwWindowHint(GLFW_SAMPLES, 16);

	window = glfwCreateWindow(640, 480, "Arkanoid 3000 (C) VikingZ", NULL, NULL);
	
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	// const GLubyte *renderer = glGetString(GL_RENDERER);
	// const GLubyte *version = glGetString(GL_VERSION);

	printinit((char *)glGetString(GL_RENDERER), (char *)glGetString(GL_VERSION));
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	
	// glEnable(GL_DEPTH_TEST);
	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_BACK);
	// glFrontFace(GL_CW);
	// glDepthFunc(GL_LESS);
	
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
		glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	// float points[] = {
	//    0.0f,  0.5f,  0.0f,
	//    0.5f, -0.5f,  0.0f,
	//   -0.5f, -0.5f,  0.0f
	// };

	// GLuint vbo = 0;
	// glGenBuffers (1, &vbo);
	// glBindBuffer (GL_ARRAY_BUFFER, vbo);
	// glBufferData (GL_ARRAY_BUFFER, 9 * sizeof (float), points, GL_STATIC_DRAW);

	// GLuint vao = 0;
	// glGenVertexArrays (1, &vao);
	// glBindVertexArray (vao);
	// glEnableVertexAttribArray (0);
	// glBindBuffer (GL_ARRAY_BUFFER, vbo);
	// glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
