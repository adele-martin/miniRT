/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:04:39 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/01/27 14:11:55 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_light_ratio(double ratio)
{
	if (ratio < 0 || ratio > 1)
		return (1);
	return (0);
}

void	parse_light(char *line, t_scene *scene)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	set_coordinates(&split_line[0], &scene->light.light_point);
	scene->light.ratio = ft_atof(split_line[2]);
	set_color(&split_line[3], &scene->light.color);
	if (validate_diameter(scene->light.ratio) || \
		validate_color(&scene->light.color) || \
		validate_light_ratio(scene->light.ratio))
		free_exit("Error. Invalid light parameters.", scene);
}
