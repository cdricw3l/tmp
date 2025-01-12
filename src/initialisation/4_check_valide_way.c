/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_check_valide_way.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:18:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/12 13:38:42 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/initialisation.h"

static void *ft_clean_arr(char **arr, int i)
{
	int j;

	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
	return(NULL);
}

static	char **ft_tmp_arr(char **arr, t_xy map)
{
	char **tmp;
	int height;
	int i;
	height = map.row;
	i = 0;
	tmp = malloc(sizeof(char *) * height);
	if(!tmp)
		return(NULL);
	while (i < height)
	{
		tmp[i] = ft_strdup(arr[i]);
		if(!tmp[i])
			return(ft_clean_arr(tmp, i));
		i++;
	}
	return(tmp);
}

void	fill_arr(char **tab, t_data *data, int col, int row)
{
	t_xy size;

	size = data->xy_data.map;
	if(tab[row][col] != '0' && tab[row][col] != 'P' 
			&& tab[row][col] != 'C' && tab[row][col] != 'E' )
		return ;
	if(tab[row][col] == 'C')
	{
		data->check_item++;
		data->map[row][col] = 'X';
	}
	if(tab[row][col] == 'E')
	{
		data->count_exit--;
		data->map[row][col] = '0';
	}
	tab[row][col] = ' ';
	if(row > 1)
		fill_arr(tab, data, col, row - 1);
	if(row < size.row - 1)
		fill_arr(tab, data, col, row + 1);
	if(col > 1)
		fill_arr(tab, data, col - 1, row);
	if(col < size.col - 1)
		fill_arr(tab, data, col + 1, row);
}

int	check_valide_way(t_data *data)
{
	char		**tab;
	char		**tmp;
	t_xy		begin;

	if (!data->map)
		return(1);
	tab = data->map;
	begin = data->xy_data.begin;
	tmp = ft_tmp_arr(tab, data->xy_data.map);
	if(!tmp)
		return(1);
	fill_arr(tmp,  data, begin.col, begin.row);
	ft_clean_arr(tmp, data->xy_data.map.row);
	if (data->check_item != data->count_item)
		return(1);
	if (data->count_exit != 0)
		return(2);
	print_map(data);
	return(0);
}
// int main(void)
// {
// 	t_data *data;
// 	t_img *img;

// 	data = initialisation_and_check("map/map2.ber");
// 	if (!data)
// 		return (1);
// 	ft_display_data_info(data);

// 	data->mlx = mlx_init();
// 	data->window = mlx_new_window(data->mlx,1280,1220,"hello");
// 	//check_valide_way(data);


// 	// bien penser a liberer cette memoire.
// 	img = malloc(sizeof(t_img));
// 	if(!img)
// 		return(1);
// 	img->img = mlx_xpm_file_to_image(data->mlx, "/home/cb/Documents/42K/so_long_render/items/trames/monster_trame.xpm", &img->width, &img->height);
// 	if(!img->img)
// 		return(1);
// 	printf("voici la taille de l'image : col %d et row %d\n", img->width, img->height);
// 	t_img *new_img;
// 	new_img = mlx_new_image(data->mlx,128,128);
// 	if(!new_img)
// 		return(1);
// 	char *addr1 = mlx_get_data_addr(new_img,&new_img->bit_per_pixel, &new_img->line_length, &new_img->endian);
// 	char *addr2 = mlx_get_data_addr(img->img,&img->bit_per_pixel, &img->line_length, &img->endian);
// 	if(!addr1 || !addr2)
// 		return(1);

// 	t_border b;

// 	b.b_color = 0xFF0000;
// 	b.border_size = 10;
// 	b.r_color = 0;
// 	b.size.col = 100;
// 	b.size.row = 100;
// 	b.targ.col = 100;
// 	b.targ.row = 100;
	
// 	ft_put_border(data,b);
// 	//mlx_loop(mlx);
// 	mlx_destroy_image(data->mlx,img->img);
// 	mlx_destroy_image(data->mlx,new_img);
// 	mlx_destroy_window(data->mlx,data->window);
// 	mlx_destroy_display(data->mlx);
// 	free(img);
// 	free(data);
// 	return(0);
// }