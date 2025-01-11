/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:13:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/11 01:17:21 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <dirent.h>
#include <X11/keysym.h>

static int	_init(t_data *data, char *map_path)
{
	
	data->map_name = map_path;
	data->map = NULL;
	data->count_item = 0;
	data->check_item = 0;
	data->count_mouvement = 0;
	data->count_exit = 0;
	data->count_begin = 0;
	data->xy_data.exit = ft_s_dimention();
	data->xy_data.begin = ft_s_dimention();
	data->xy_data.map = ft_s_dimention();
	data->xy_data.screen_size = ft_s_dimention();
	mlx_get_screen_size(data->mlx, &data->xy_data.screen_size.col,
				&data->xy_data.screen_size.row);
	if(data->xy_data.screen_size.col == 0 
			|| data->xy_data.screen_size.row == 0)
		return(1);
	return(0);
}


void ft_clean(t_data **d)
{
    t_data *data = *d;
    int i;

    i = 0;
    while(i < 11)
    {
        printf("%s\n", data->map[i]);
        free(data->map[i]);
        i++;

    }
    free(data->map);
    free(data);
}


int main(void)
{
    printf("start de la fonction\n");

    t_data *data;

    data = malloc(sizeof(t_data));
    assert(data != NULL);
    data->mlx = mlx_init();
    _init(data,"map/map2.ber");

    data->map = get_map(data);

    // int i = 0;
    // while(i < 11)
    // {
    //     printf("%s\n", data->map[i]);
    //     i++;
    // }
    

    assert(check_map(data) == 0);

    printf("voici les dimentions de la map col: %d et row: %d\n", data->xy_data.map.col, data->xy_data.map.row);
    printf("voici la position du personage y = %d et x = %d\n", data->xy_data.begin.col, data->xy_data.begin.row );
    printf("voici la position de la sortie : x: %d et y: %d\n", data->xy_data.exit.col,data->xy_data.exit.row);

    check_valide_way(data);
    
    //ft_clean(&data);
    //free_memory(&data, 0);


    return(0);
}