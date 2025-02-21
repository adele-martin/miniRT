/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:35:20 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/02/21 16:16:49 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

int	convert_color(t_color color)
{
	int	rgb;
	int	opacity;

	opacity = 255;
	rgb = (color.r << 24) + (color.g << 16) + (color.b << 8) + opacity;
	return (rgb);
}

double object_intersects(t_object object, t_ray ray, double t, t_scene *s)
{
    ray_intersects_sp(ray, object, &t, s);
	ray_intersects_pl(ray, object, &t, s);
	ray_intersects_cy(ray, object, &t, s);
	return (t);
}


void find_nearest_intersection(t_ray ray, t_scene *s)
{
	double closest_t = INFINITY;
	s->intersec.self = NULL;
	double t = -1;
	t_object *current = s->object;
	t_object *closest_object = NULL;
	while (current)
	{
	t = object_intersects(*current, ray, t, s);
	if (t > 0.001 && t < closest_t)
	{
		closest_t = t;
		s->intersec.self = current;
		closest_object = current;
	}
	current = current->next;
	if (closest_object)
    {
        s->intersec.t = closest_t;
        s->intersec.self = closest_object;
        ray_intersects_sp(ray, *closest_object, &closest_t, s);
        ray_intersects_pl(ray, *closest_object, &closest_t, s);
        ray_intersects_cy(ray, *closest_object, &closest_t, s);
    }
	}
}

// void	put_color_pixel(double p_x, double p_y, t_scene *scene, t_ray ray)
// {
// 	int			color;
// 	t_color		rgb;

// 	(void)ray;
// 	find_nearest_intersection(ray, scene);
// 	if (scene->intersec.self != NULL)
//     {
//         if (scene->intersec.self->type == 1) // Sphere
//             rgb = scene->intersec.color;
//         if (scene->intersec.self->type == 2) // Plane
//             rgb = scene->intersec.color;
//         if (scene->intersec.self->type == 3) // Cylinder
// 			rgb = scene->intersec.color;
//     }
//     else
// 		rgb = scene->ambience.color;
// 	color = convert_color(rgb);
// 	mlx_put_pixel(scene->img, p_x, p_y, color);
// }

void	put_color_pixel(double p_x, double p_y, t_scene *scene, t_ray ray)
{
	int			color;
	t_color		rgb;

	find_nearest_intersection(ray, scene);
	if (scene->intersec.self)
		rgb = light_calc(scene);
	else
		rgb = scene->ambience.color;
	color = convert_color(rgb);
	mlx_put_pixel(scene->img, p_x, p_y, color);
}
