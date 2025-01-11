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

void	exit_game(t_data *data)
{

	printf("clean memory...\n");
    if (data->mlx)
    {
        // if(data->img->img)
        //     mlx_destroy_image(data->mlx, data->img->img);
        if(data->window)
            mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
    }
	free_memory(data, 0);
	printf("END GAME\n");
	exit (0);
}

void	_putwall(t_data *data, void *im)
{
	int w;
	int h;
	int i;
	int j;

	w = data->xy_data.map.col;
	h = data->xy_data.map.row;
	i = 0;
	while (i < h *TILD_SIZE)
	{
		j = 0;
		while (j < w * TILD_SIZE)
		{
			if (i == 0 || i == (h - 1) * TILD_SIZE)
			{
				mlx_put_image_to_window(data->mlx,data->window,im,j,i);
			}
			else
				if (j == 0 || j == (w - 1) * TILD_SIZE)
					mlx_put_image_to_window(data->mlx,data->window,im,j,i);
			j+= TILD_SIZE;
		}
		i += TILD_SIZE;
	}
}

void	ft_put_wall(t_data *data)
{
	void	*im;
	

	im = data->img_set[2]->img;
	if(!im)
	{
		printf("erreur douverutre de l'item\n");
		return ;
	}
	else
		printf("push image et h %d sur map %d X ...\n",data->xy_data.map.col,data->xy_data.map.row);
	_putwall(data, im);
}

void    start_game(t_data *data)
{

    
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
		start_game(&data);
		//free_memory(data, 13);
		
	}
	return (0);
}
