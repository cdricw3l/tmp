/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/07 15:59:00 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

void	fill_arr(char **tab, int target, t_data *data, int col, int row)
{
	t_xy size;

	size = data->xy_data.map;
	print_dimention(data->xy_data, 'm');
	if(col < 0 || col >= size.col - 1 || row < 0 ||  row  >= size.row - 1)
		return ;
		
	if(tab[row][col] == 'F' )
		return ;

	
	tab[row][col] = 'F';
    
	fill_arr(tab, target, data, col, row - 1);
	fill_arr(tab, target, data, col, row + 1);
	fill_arr(tab, target, data, col - 1, row);
	fill_arr(tab, target, data, col + 1, row);
	
	print_map(data);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	int			target;
	t_xy		begin;

	if (!data)
		return(1);
	tab = data->map;
	begin = data->xy_data.begin;
	target = tab[begin.col][begin.row];
	PRINT("\nstatdqdqwdqdq\n  ");
	(void)target;
	//printf("vvoici : target %c col %d row %d", target, begin.col, begin.row);
	//fill_arr(tab, target, data, begin.col, begin.row);
	//print_map(data);
	// if (data->check_item != data->count_item)
	// 	return(1);
	return(0);
}
int main(void)
{
	t_data *data;
	char *path;

	path = "map/map2.ber";
	data = initialisation_and_check(path);
	if (!data)
		return (1);
	//ft_display_data_info(data);
	check_valide_way(data);                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	//free_memory(data,1);
}