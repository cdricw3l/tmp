/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/12 11:17:09 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	clean_image_memory(t_data **d, t_img **data, int index)
{
	int	i;
 
	(void)index;
    i = 0;
    if((unsigned long)(*d)->img_set_global == 0xbebebebebebebebe)
        return(1);
	
    while (i < SET_SIZE)
	{   
        if((*d)->mlx)
            mlx_destroy_image((*d)->mlx,data[i]->img);
        else
            free(data[i]->img);
        free(data[i]->class);
        free(data[i]);
		i++;
	}
    free(data);
	return (1);
}

void	free_path_memory(char **path_g, char **path_l, char **path_r)
{
	free(path_g);
	free(path_l);
	free(path_r);
}


void	*free_memory(t_data **data, int err)
{
    char **map;

    map =  (*data)->map;
    if(err != -1)
    {
        if(map)
        {
            while (*map)
            {
                free(*map);
                map++;
            }
        }
        if((*data)->img_set_global)
            clean_image_memory(data, (*data)->img_set_global, SET_SIZE);

    }
    //if((*data)->window)
    mlx_destroy_window((*data)->mlx, (*data)->window);
    mlx_destroy_display((*data)->mlx);
   
    free((*data));
    error_layer(err);
    exit(0);
	return (NULL);
}

