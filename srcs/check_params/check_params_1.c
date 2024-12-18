/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 11:44:49 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int ft_is_close(char **map, int  hauteur, int largeur)
{
    int i;
    int j;

    i = 0;
    while(i <  hauteur)
    {
        j = 0;
        while (j < largeur)
        {
            if(i == 0 || i == hauteur - 1)
            {
                if(map[i][j] != 49)
                {
                    printf("voi le  ca qui posent probleme :%d vooici i : %d, voici j : %d\n", map[i][j], i, j);
                    return (1);
                }

            }
            else
            {
                if(j == 0 || j == largeur - 1)
                {
                    if(map[i][j] != 49)
                    {
                         printf("voi le  ca qui posent probleme 2:%d\n", map[i][j]);
                        return (1);                    
                    }
                }
            }
            j++;
        }
        i++;
    }
    return(0);
}

int ft_check_params(char **map, int  hauteur, int largeur)
{
    if(is_rectangle(hauteur, largeur) || are_exit(map, hauteur, largeur))
        return (1);
    if(are_item(map, hauteur, largeur) || are_start(map, hauteur, largeur))
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    char **map;
    (void)argc;
    map = ft_parse_params(argv[1], 6, 35);

    ft_print_map(map, 6, 35);

    int k = ft_is_close(map, 6, 35);
    printf("%d\n", k);
    return(0);
}