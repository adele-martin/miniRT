/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:38:17 by ademarti          #+#    #+#             */
/*   Updated: 2025/02/27 15:14:01 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	split_double(char *input_coords, double *x, double *y, double *z)
{
	char	**coords;

	coords = ft_split(input_coords, ',');
	if (!coords)
	{
		free_split(coords);
		return (-1);
	}
	*x = ft_atof(coords[0]);
	*y = ft_atof(coords[1]);
	*z = ft_atof(coords[2]);
	free_split(coords);
	return (0);
}

int	set_coordinates(char **line, t_vector *point)
{
	double	x;
	double	y;
	double	z;

	split_double(line[1], &x, &y, &z);
	point->x = x;
	point->y = y;
	point->z = z;
	return (0);
}

int	set_orientation(char **line, t_vector *vector)
{
	double	x;
	double	y;
	double	z;

	split_double(line[1], &x, &y, &z);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (0);
}

void	parse_camera(char *line, t_scene *scene)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (validate_line_format(split_line, 4))
		handle_parse_error(split_line, scene, ERR_INVAL_C_FORMAT);
	set_coordinates(&split_line[0], &scene->camera.origin);
	set_orientation(&split_line[1], &scene->camera.forward_v);
	if (validate_numeric_value(split_line[3]))
		handle_parse_error(split_line, scene, ERR_INVAL_FOV);
	scene->camera.fov = ft_atoi(split_line[3]);
	if (validate_orientation(&scene->camera.forward_v) || \
		validate_fov(scene->camera.fov))
		handle_parse_error(split_line, scene, ERR_INVAL_COORD_FOV);
	free_split(split_line);
}
