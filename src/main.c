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

void	my_mlx_pixel_put(t_img *new, t_img *frame,t_xy xyf)
{
	char	*dst;
	char	*src;
    int i;

    i = 0;
    while (i < xyf.row)
    {
        int j = 0;
        while (j < xyf.col)
        {
            printf("ECRITURE colors \n");
            src = frame->addr + (j * frame->line_length + i * (frame->bit_per_pixel / 8));
            dst = new->addr + (j * new->line_length + i * (new->bit_per_pixel / 8));
	        *(unsigned int*)dst = *(unsigned int*)src;
            j++;
        }
        i++;
    }
	
}

t_img *ft_image_drawer(t_data *data)
{
	t_img new;
	int i;
	int j;
	t_xy	draw_area;

	i = 0;
	j = 0;
	new.img = mlx_new_image(data->mlx, TILD_SIZE * data->xy_data.map.col, TILD_SIZE * data->xy_data.map.row);
	if(!new.img)
		return(NULL);
	new.addr = mlx_get_data_addr(data->mlx,&new.bit_per_pixel, &new.line_length, &new.endian);
	if(!new.addr)
		return(NULL);
	while (i < 1)
	{
		j = 0;
		while (j < 1)
		{
			draw_area.col = j;
			draw_area.row = i;
			my_mlx_pixel_put(&new, data->img_set_global[i], draw_area);
			j++;
		}
		i++;	
	}
	mlx_put_image_to_window(data->mlx,  data->window, new.img,0,0);
	return(NULL);

}

void    start_game(t_data *data)
{

    data->window = mlx_new_window(data->mlx, TILD_SIZE * data->xy_data.map.col, TILD_SIZE * data->xy_data.map.row, "hello");
    if(!data->window || !data->mlx)
    {
        return ;
    }
	ft_image_drawer(data);
	// while (1)
	// {
	// 	if(char_layer(*data,0) == NULL)
	// 		return ;
	// 	/* code */
	// }
	
    mlx_hook(data->window, 2, 1L<<0 ,manage_keyboard, data);
    printf("adresse 1: %p et adresse 2: %p\n", data->mlx, data->window);
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
		ft_display_data_info(data); // a suuprimmer pour le rendu
		start_game(data);
		printf("liberation de la memoire\n");
		free_memory(&data, 1);
		
	}
	return (0);
}
