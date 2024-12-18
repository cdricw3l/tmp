/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:41:56 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 10:27:34 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void  ft_get_dimentions(int fd, t_data  *img)
{
    char *str = "";
    int largeur;
    int hauteur;
    //int i = 0;
    //char **map;
    
    largeur = 0;
    hauteur = 0;
    while (str != NULL)
    {
        str = get_next_line(fd);
        if (str != NULL)
        {
            if (largeur == 0)
                largeur = ft_strlen(str);
            hauteur++;
        }
    }
    img->dimention.hauteur = hauteur;
    img->dimention.largeur = largeur;    
}

void    ft_print_map(char **map, int hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while (i < hauteur)
    {
        j = 0;
        while(j < largeur)
        {
            printf("%c", map[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
    
}
