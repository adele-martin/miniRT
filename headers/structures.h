/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <adelemartin@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:11:01 by ademarti          #+#    #+#             */
/*   Updated: 2025/01/21 13:10:56 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_ambience
{
	float		light_ratio;
	t_color	color;
}	t_ambience;

//FOV: Angle of what you see.
typedef struct s_camera
{
	t_point		viewpoint;
	t_vector	orientation;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_point	light_point;
	double	diameter;
	t_color	color;
}	t_light;

typedef struct s_sp
{
	t_point	center;
	double	diameter;
	t_color	color;
}	t_sp;

typedef struct s_pl
{
	t_point		plane_point;
	t_vector	normal_vector;
	t_color		color;
}	t_pl;

typedef struct s_cy
{
	t_point		center;
	t_vector	axis;
	double		diameter;
	double		height;
	t_color		color;
}	t_cy;

typedef struct s_scene
{
	void		*mlx_ptr;
	void		*win;
	t_ambience	ambience;
	t_camera	camera;
	t_light light;
}	t_scene;

#endif

