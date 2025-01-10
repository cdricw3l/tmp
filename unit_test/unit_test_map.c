/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:13:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/11 00:15:27 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

#include <dirent.h>
#include <X11/keysym.h>


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

    data->map_name =  "map/map3.ber";

    data->map = get_map(data);

    int i = 0;
    while(i < 11)
    {
        printf("%s\n", data->map[i]);
        i++;
    }
    
    ft_clean(&data);
    //free_memory(&data, 0);


    return(0);
}