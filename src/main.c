/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:06:08 by vvu               #+#    #+#             */
/*   Updated: 2023/10/27 20:56:19 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	data;

	if (error_check(argc, argv) == 1)
		return (1);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd == -1)
	{
		ft_putstr_fd("Error\nCould not open file.\n", 2);
		return (1);
	}
	if (init_data(&data))
		return (1);
	if (read_file_and_parse(&data) == 1)
		return (1);
	if (init_window(&data))
		return (1);
	set_color_to_floor_ceiling(&data);
	render_game(&data);
	hook_keys_loop(&data);
	free_texture(&data);
	return (0);
}
