// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cbouhadr <cbouhadr@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/05 14:56:23 by cb                #+#    #+#             */
// /*   Updated: 2025/01/05 14:56:24 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../include/so_long.h"

void ft_slice_img(t_img *img)
{
    printf("voici les info sur l'image: \n");
    printf(" addresse img %p, bit_px %d, frame size %d \n", img, img->bit_per_pixel, img->frame_size);
    printf(" line len img %d, img class %s, largeur %d \n", img->line_length, img->class, img->width);
}


void    start_game(t_data *data)
{

	t_xy win;

	win.col = data->xy_data.map.col;
	win.row = data->xy_data.map.row;

	data->window = mlx_new_window(data->mlx,win.col * TILD_SIZE, win.row * TILD_SIZE, "hello");
    if(!data->window || !data->mlx)
    {
        return ;
    }
	ft_image_drawer(data);
    mlx_hook(data->window, 2, 1L<<0 ,manage_keyboard, data);
   	mlx_hook(data->window, 17, 1L<<0 ,close_windows, data);
    mlx_loop(data->mlx) ;
}

	
int	main(int argc, char *argv[])
{
	t_data		*data;

	if (argc != 2)
		return (error_layer(0));
	else
	{
		data = initialisation_and_check(argv[1]);
		if (!data)
			return (1);
		ft_display_data_info(data);
		start_game(data);
		free_memory(&data, 1);
		
	}
	return (0);
}
