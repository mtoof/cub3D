/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:24:51 by mtoof             #+#    #+#             */
/*   Updated: 2023/09/25 17:03:24 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	my_mlx_pixel_put(t_cub3d *data, double width, double height, unsigned int color)
{
	char	*dst;
	int		y;
	int		x;

	x = round(width);
	y = round(height);
	data->img->addr = mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	dst = data->img->addr + (y * data->img->line_length + \
	x * (data->img->bits_per_pixel / 8));
	if ((x >= 0 && x < X) && (y >= 0 && y < Y))
		*(unsigned int *)dst = color;
}
