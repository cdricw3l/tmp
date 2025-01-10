/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:07:49 by cb                #+#    #+#             */
/*   Updated: 2025/01/11 00:02:45 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
        if((*data)->img_sets)
            clean_image_memory(data, &(*data)->img_sets, SET_SIZE);

    }
    printf("MEMORYYYYYYYY");
    if((unsigned long)(*data)->mlx !=  0xbebebebebebebebe)
        mlx_destroy_display((*data)->mlx);
    error_layer(err);
    exit(0);
	return (NULL);
}
int	clean_image_memory(t_data **d, t_img_sets **data, int index)
{
	int	i;
 
	(void)index;
    i = 0;
    if((unsigned long)(*d)->img_sets == 0xbebebebebebebebe)
        return(1);
	
    while (i < SET_SIZE)
	{   
        mlx_destroy_image((*d)->mlx,(*data)->img_set_global[i]->img);
        mlx_destroy_image((*d)->mlx,(*data)->img_set_left[i]->img);
        mlx_destroy_image((*d)->mlx,(*data)->img_set_right[i]->img);
        free((*data)->img_set_global[i]->class);
        free((*data)->img_set_left[i]->class);
        free((*data)->img_set_right[i]->class);
        free((*data)->img_set_global[i]);
        free((*data)->img_set_left[i]);
        free((*data)->img_set_right[i]);
		i++;
	}
    free((*data)->img_set_global);
    free((*data)->img_set_left);
    free((*data)->img_set_right);
    free((*data));
	return (1);
}

void	free_path_memory(char **path_g, char **path_l, char **path_r)
{
	
	free(path_g);
	free(path_l);
	free(path_r);
}
