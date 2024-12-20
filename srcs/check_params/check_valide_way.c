/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 14:11:06 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	fill_arr2(char **tab, int target, t_dimention size, int col, int row)
{
    int counter;

    counter = 0;
    
	if(col < 0 || col >= size.largeur || row < 0 ||  row  >= size.hauteur)
		return counter;
		
	if(tab[row][col] == 'C' || tab[row][col] != target)
    {
        counter++;
        printf("item trouve");
		return counter;
    }

	
    
	return counter + fill_arr2(tab, target, size, col, row - 1);
	return counter + fill_arr2(tab, target, size, col, row + 1);
	return counter + fill_arr2(tab, target, size, col - 1, row);
	return counter + fill_arr2(tab, target, size, col + 1, row);
}


void ft_check_valide_way(char **tab, t_dimention size, t_dimention begin)
{
    int target;
    int counter;

    
    target = tab[begin.hauteur][begin.largeur];
	counter = fill_arr2(tab, target, size, begin.largeur, begin.hauteur);
    (void)counter;
    printf("voici le counter %d\n", counter); 
}