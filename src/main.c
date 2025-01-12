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

int		ft_get_img_idx(t_data *data,char c)
{
	if(c == '1')
		return(5);
	if(c == 'X')
		return(4);
	if(c == 'P' && data->char_state == LEFT)
		return(0);
	if(c == 'P' && data->char_state == RIGHT)
		return(1);
	if(c == 'E')
		return(2);
	return(6);
}
void	my_mlx_pixel_put(t_img *new, t_img *frame,t_xy xyf)
{
	char	*dst;
	char	*src;
    int i;

    i = 0;
    while (i < TILD_SIZE)
    {
        int j = 0;
        while (j < TILD_SIZE)
        {
            //printf("ECRITURE colors  col %d et row %d\n", frame->line_length, xyf.row);
            src = frame->addr + (j * frame->line_length + i * (frame->bit_per_pixel / 8));
            dst = new->addr + ((j + (xyf.row)) * new->line_length + (i + (xyf.col)) * (new->bit_per_pixel / 8));
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
	t_xy	size;
	(void)draw_area;
	i = 0;
	size = data->xy_data.map;
	print_dimention(data->xy_data, P_MAP);
	new.img = mlx_new_image(data->mlx, TILD_SIZE * data->xy_data.map.col, TILD_SIZE * data->xy_data.map.row);
	if(!new.img)
		return(NULL);
	new.addr = mlx_get_data_addr(new.img,&new.bit_per_pixel, &new.line_length, &new.endian);
	if(!new.addr)
		return(NULL);
	printf(" voici %d", new.line_length);
	//ft_slice_img(&new);
	while (i < size.row)
	{
		j = 0;
		while (j <  size.col)
		{
			draw_area.col = j * TILD_SIZE;
			draw_area.row = i *  TILD_SIZE;
			int path = ft_get_img_idx(data,data->map[i][j]);
			if(path >= 0 && path < 6)
				my_mlx_pixel_put(&new, data->img_set_global[path], draw_area);
			j++;
		}
		i++;	
	}
	mlx_put_image_to_window(data->mlx,  data->window, new.img,0,0);
	printf("image detruite");
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
		ft_display_data_info(data); // a suuprimmer pour le rendu
		start_game(data);
		printf("liberation de la memoire\n");
		free_memory(&data, 1);
		
	}
	return (0);
}
