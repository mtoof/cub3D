/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:04:42 by vvu               #+#    #+#             */
/*   Updated: 2023/09/26 12:47:22 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	mouse_handler(t_cub3d *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	free_texture(data);
	exit(0);
}

int	key_press_handler(int key, t_cub3d *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		free_texture(data);
		exit(0);
	}
	data->keys[key] = TRUE;
	return (0);
}

int	key_release_handler(int key, t_cub3d *data)
{
	data->keys[key] = FALSE;
	return (0);
}

void	update_player_coordinates(t_cub3d *data)
{
	int	x;
	int	y;

	y = round(data->player->tmp_player_y);
	x = round(data->player->tmp_player_x);
	if (data->raw_map[y / (BLOCK_SIZE / PLAYER_SIZE)][x / (BLOCK_SIZE
			/ PLAYER_SIZE)] == '1')
		return ;
	data->player->player_x = data->player->tmp_player_x;
	data->player->player_y = data->player->tmp_player_y;
	render_game(data);
}

void	arrow_keys(t_cub3d *data)
{
	if (data->keys[RIGHT])
	{
		data->player->player_angle += ANGLE;
		if (data->player->player_angle >= 360)
			data->player->player_angle -= 360;
	}
	if (data->keys[LEFT])
	{
		data->player->player_angle -= ANGLE;
		if (data->player->player_angle < 0)
			data->player->player_angle += 360;
	}
}

void	move_keys(t_cub3d *data, double player_rad_angle)
{
	if (data->keys[W])
	{
		data->player->tmp_player_x -= cos(player_rad_angle) * SPEED;
		data->player->tmp_player_y -= sin(player_rad_angle) * SPEED;
	}
	if (data->keys[S])
	{
		data->player->tmp_player_x += cos(player_rad_angle) * SPEED;
		data->player->tmp_player_y += sin(player_rad_angle) * SPEED;
	}
	if (data->keys[A])
	{
		data->player->tmp_player_x -= sin(player_rad_angle) * SPEED;
		data->player->tmp_player_y += cos(player_rad_angle) * SPEED;
	}
	if (data->keys[D])
	{
		data->player->tmp_player_x += sin(player_rad_angle) * SPEED;
		data->player->tmp_player_y -= cos(player_rad_angle) * SPEED;
	}
}

int	keys(t_cub3d *data)
{
	double	player_rad_angle;

	data->player->tmp_player_x = data->player->player_x;
	data->player->tmp_player_y = data->player->player_y;
	player_rad_angle = angle_rad(data->player->player_angle);
	if (data->keys[W] || data->keys[S] || data->keys[A] || data->keys[D])
		move_keys(data, player_rad_angle);
	if (data->keys[RIGHT] || data->keys[LEFT])
		arrow_keys(data);
	update_player_coordinates(data);
	return (0);
}

void	hook_keys_loop(t_cub3d *data)
{
	mlx_hook(data->mlx_window, 2, 1L << 0, key_press_handler, data);
	mlx_hook(data->mlx_window, 3, 1L << 1, key_release_handler, data);
	mlx_loop_hook(data->mlx_ptr, keys, data);
	mlx_hook(data->mlx_window, 17, 0, mouse_handler, data);
	mlx_loop(data->mlx_ptr);
}
