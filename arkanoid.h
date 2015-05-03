/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 12:08:22 by gleger            #+#    #+#             */
/*   Updated: 2015/04/28 16:00:09 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>
# include <glfw3.h>
# include <math.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[0;33m"
# define YELLOW "\033[1;33m"
# define PURPLE "\033[0;35m"
# define GRAY "\033[1;30m"
# define NC "\033[0m"

# ifndef M_PI
#  define M_PI 3.141592653
# endif

# define INIT_COLOR(X) t_color X = {.red = 0.0, .blue = 0.0, .green = 0.0}

typedef struct s_color
{
	float red;
	float blue;
	float green;

}				t_color;

void		drawmap();
void		drawball();
void		drawpaddle();
void 		DrawSquare(t_color colors, float var, float buff, float max);
void 		DrawCircle(float cx, float cy, float r, int num_segments);

#endif