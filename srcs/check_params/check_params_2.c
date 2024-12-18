/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:39:44 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 11:26:49 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int is_rectangle(int hauteur, int largeur)
{
    if (hauteur == largeur)
        return(1);
    return (0);
}

int are_exit(char **map, int  hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            if(map[i][j] == 'E')
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}

int are_item(char **map, int  hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            if(map[i][j] == 'C')
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}

int are_start(char **map, int  hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            if(map[i][j] == 'P')
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}


