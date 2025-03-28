/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:10:52 by ademarti          #+#    #+#             */
/*   Updated: 2025/02/28 14:47:04 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

/*maybe implement
	//translation(key, scene);
	//rotation(key, scene);
	//zoom(key, scene);
	//update(scene);
*/
void	key_board(mlx_key_data_t key, t_scene *scene)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(scene->mlx_ptr);
		free_exit("Closing window and exiting program\n", scene, 0);
		return ;
	}
}

void	render_image(t_scene *scene)
{
	double		pixel_x;
	double		pixel_y;
	t_ray		ray;

	pixel_x = 0;
	while (pixel_x < scene->canvas_width)
	{
		pixel_y = 0;
		while (pixel_y < scene->canvas_height)
		{
			ray = create_ray(pixel_x, pixel_y, scene->camera.origin, scene);
			put_color_pixel(pixel_x, pixel_y, scene, ray);
			pixel_y++;
		}
		pixel_x++;
	}
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2 || validate_name(av[1]))
		free_exit("Error. Please enter the scene (*.RT) argument.\n", \
					NULL, 1);
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		free_exit("Memory allocation error.", scene, 1);
	init_mlx(scene);
	parsing(av[1], scene);
	create_viewport(scene);
	mlx_loop_hook(scene->mlx_ptr, (t_hookfunc)render_image, scene);
	mlx_key_hook(scene->mlx_ptr, (t_mlx_keyfunc)key_board, scene);
	mlx_loop(scene->mlx_ptr);
	return (0);
}
