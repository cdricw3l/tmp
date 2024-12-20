/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:47:03 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/20 10:07:08 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_arr(char **tab, int target, t_dimention size, int col, int row)
{
	if(col < 0 || col >= size.largeur || row < 0 ||  row  >= size.hauteur)
		return ;
		
	if(tab[row][col] == 'F' || tab[row][col] != target)
		return ;

	tab[row][col] = 'F';
    
	fill_arr(tab, target, size, col, row - 1);
	fill_arr(tab, target, size, col, row + 1);
	fill_arr(tab, target, size, col - 1, row);
	fill_arr(tab, target, size, col + 1, row);
}


void ft_flood_fill(char **tab, t_dimention size, t_dimention begin)
{
    int target;

    target = tab[begin.hauteur][begin.largeur];
	fill_arr(tab, target, size, begin.largeur, begin.hauteur);
	
}


// char **make_area(char *zone[], t_arr_point *size)
// {
// 	int larg;
// 	int hauteur;
// 	int i;
// 	int k;
// 	int j;
// 	char **area;

// 	hauteur = size->row;
// 	larg = size->col;
// 	printf("voici la hauteur : %d et voici la largeur %d\n",hauteur, larg);
// 	i = 0;
// 	k = 0;
// 	area = malloc(sizeof(char *) * hauteur);
// 	if(!area)
// 	{
// 		printf("erreur\n");
// 		return (NULL);
// 	}
// 	while (i < hauteur)
// 	{
// 		j = 0;
// 		k = 0;
// 		area[i] = malloc(sizeof(char *) * larg);
// 		if(!area[i])
// 		{
// 			printf("erreur\n");
// 			return (NULL);
// 		}
// 		while (j < larg)
// 		{
// 			area[i][j] = zone[i][k];
// 			j++;
// 			k += 2;
// 		}
// 		i++;
// 	}
// 	return(area);
// }

// int main(void)
// {
// 	char **area;
    
// 	t_arr_point size = {8, 5};
// 	t_arr_point begin = {0, 0};
// 	char *zone[] = {
// 		"1 1 1 1 1 1 1 1",
// 		"1 0 0 0 1 0 0 1",
// 		"1 0 0 1 0 0 0 1",
// 		"1 0 1 1 0 0 0 1",
// 		"1 1 1 1 1 1 1 1",
// 	};
	
// 	area =  make_area(zone, &size);
// 	(void)area;
	
// 	int i = 0;
// 	int j;

// 	while (i < size.row)
// 	{
// 		j = 0;
// 		while (j < size.col)
// 		{
// 			printf("%c ", area[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
	
// 	// //flood_fill(area, &size, begin);
    
//     // begin.col  = 4;
//     // begin.row  = 1;
// 	flood_fill(area, &size, begin);
//     begin.col  = 2;
//     begin.row  = 2;
// 	flood_fill(area, &size, begin);
//     begin.col  = 5;
//     begin.row  = 1;
// 	flood_fill(area, &size, begin);
//     i = 0;
// 	while (i < size.row)
// 	{
// 		j = 0;
// 		while (j < size.col)
// 		{
// 			printf("%c ", area[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
	
// 	return (0);
// }