/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 12:26:06 by cbouhadr         ###   ########.fr       */
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
                    return (1);

            }
            else
                if(j == 0 || j == largeur - 1)
                {
                    if(map[i][j] != 49)
                        return (1);                    
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



// int main(int argc, char *argv[])
// {
//     char **map;
//     t_data img;

//     int fd = open(argv[1],O_RDONLY);
//     if(argc != 2)
//     {
//         perror(ft_error_return(1));
//         return (1);
//     }
//     if (fd == -1)
//     {
//         perror(ft_error_return(2));
//         return (1);
//     }

//     ft_get_dimentions(fd, &img);
//     printf("voicci les dimention: h: %d et l: %d\n", img.dimention.hauteur, img.dimention.largeur);
//     map = ft_parse_params(argv[1], img.dimention.hauteur, img.dimention.largeur);
//     //ft_print_map(map, img.dimention.hauteur, img.dimention.largeur);
//     int k = ft_is_close(map, img.dimention.hauteur, img.dimention.largeur);
//     printf("%d\n", k);
//     return(0);
// }