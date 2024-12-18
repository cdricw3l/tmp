/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unit_check_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:43:46 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 13:08:54 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <assert.h>


int main(void)
{
    int     fd;
    t_data  map;
    
    char *no_close_map = "map/error_map/no_close.ber";
    // char *no_exit_map = "map/error_map/no_exit.ber";
    // char *no_item_map = "map/error_map/no_item.ber";
    // char *no_rectangle = "map/error_map/no_rectangle.ber";
    // char *no_start = "map/error_map/no_item.ber";
    // char *nothing =  "map/error_map/nothing.ber";

    printf("%s\n", no_close_map);
    fd = open(no_close_map, O_RDONLY);
    if (fd == -1)
    {
        printf("erreur  d'vouverture du fichier \n");
        return (1);
    }
    ft_get_dimentions(fd, &map);
    printf("voici les dimention %d, et %d", map.dimention.hauteur, map.dimention.largeur);
    


}