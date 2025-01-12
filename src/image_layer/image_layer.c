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

void	my_mlx_pixel_put(t_img *dst, t_img *new,t_xy xyf)
{
	char	*d;
	char	*s;
    int i;
    int j;

    i = 0;
    while (i < TILD_SIZE)
    {
        j = 0;
        while (j < TILD_SIZE)
        {
            s = new->addr + (j * new->line_length + i * (new->bit_per_pixel / 8));
            d = dst->addr + ((j + (xyf.row)) * dst->line_length + (i + (xyf.col)) * (dst->bit_per_pixel / 8));
	        *(unsigned int*)d = *(unsigned int*)s;
            j++;
        }
        i++;
    }
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

    new.img = mlx_new_image(data->mlx, (size.col * TILD_SIZE), (size.row * TILD_SIZE) );
    if(!new.img)
        return(NULL);
    new.addr = mlx_get_data_addr(new.img,&new.bit_per_pixel, &new.line_length, &new.endian);
    if(!new.addr)
        return(NULL);
    while (i < data->xy_data.map.row)
    {
        j = 0;
        while (j < data->xy_data.map.col)
        {
            t_xy dest;
            dest.row = i * TILD_SIZE;
            dest.col = j * TILD_SIZE;
            int path = ft_get_img_idx(data, data->map[i][j]);
            if(path > -1 && path < 6)
                my_mlx_pixel_put(&new, data->img_set_global[path], dest);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(data->mlx,data->window,new.img,0,0);
    mlx_destroy_image(data->mlx,new.img);
	return(NULL);

}

t_img *ft_image_drawer(t_data *data)
{

    initial_draw(data);

    return(NULL);
}
