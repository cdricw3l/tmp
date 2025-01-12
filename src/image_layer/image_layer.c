// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   image_layer.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/06 11:33:22 by cb                #+#    #+#             */
// /*   Updated: 2025/01/09 05:52:46 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */


#include "../../include/image_layer.h"



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

int ft_draw_hero(t_data *data, t_xy init, t_img *new)
{

    int row;
    int col;

    col = init.col;
    row = init.row;
    t_xy draw_area = {0,0};
	int path = ft_get_img_idx(data,data->map[row][col]);
    
	if(path >= 0 && path < 6)
	    my_mlx_pixel_put(new, data->img_set_global[path], draw_area);
    printf("impression du hero ok %d et %d \n", col, row);
    //path = ft_get_img_idx(data,data->map[data->xy_data.begin.row][data->xy_data.begin.col]);
    mlx_put_image_to_window(data->mlx,data->window,new->img, 1000, row);
    return(0);
}
t_img *initial_draw(t_data *data)
{
	t_img new;
	int i;
	int j;
	t_xy	draw_area;
	t_xy	size;
	(void)draw_area;
	i = 0;
	size = data->xy_data.map;
    data->window = mlx_new_window(data->mlx, TILD_SIZE * data->xy_data.map.col, TILD_SIZE * data->xy_data.map.row, "hello");
    mlx_hook(data->window, 2, 1L<<0 ,manage_keyboard, data);
	return(NULL);

}

t_img *ft_image_drawer(t_data *data)
{

    initial_draw(data);
    return(NULL);
}
