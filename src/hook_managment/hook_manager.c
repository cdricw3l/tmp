/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by cbouhadr          #+#    #+#             */
/*   Updated: 2025/01/12 13:48:59 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/hook_managment.h"

int ft_is_keycode_in_set(int keycode)
{
	if (keycode == 97 
			||keycode == 100
			|| keycode == 115
			|| keycode == 119
			|| keycode == 65361 
			|| keycode == 65362
			|| keycode == 65363
			|| keycode == 65364)
		return(0);
	return(1);
}

void	ft_update_mouvement(t_data *g, t_xy *begin, t_xy init)
{
	g->count_mouvement++;
	if (g->map[begin->row][begin->col] == 'X')
	{
		g->count_item--;
		if (g->count_item == 0)
		{
			g->map[g->xy_data.exit.row][g->xy_data.exit.row] = 'E';
		}
		g->map[begin->row][begin->col] = 'P';
		g->map[init.row][init.col] = ' ';
	}
	else
	{
		//
			// if(g->count_item == 0)
			// 	exit_game(data);
		g->map[begin->row][begin->col] = 'P';
		g->map[init.row][init.col] = ' ';
		ft_image_drawer(g);
	}
	print_map(g);
}

void	ft_update_position(t_data *g, int key, t_xy *b)
{
	t_xy	i;

	i.col = g->xy_data.begin.col;
	i.row = g->xy_data.begin.row;
	printf("position initial %d et %d\n", key, i.row);
	if (key == 97 || key == 65362)
		if (g->map[b->row - 1][g->xy_data.begin.col] != '1')
			b->row -= 1;
	if (key == 100 || key == 65363)
		if (g->map[b->row][b->col + 1] != '1')
			b->col += 1;
	if (key == 115 || key == 65364)
		if (g->map[b->row + 1][b->col] != '1')
			b->row += 1;
	if (key == 119 || key == 65361)
		if (g->map[b->row][b->col - 1] != '1')
			b->col -= 1;
	if (i.row != b->col || i.row != b->row)
	{
		g->map[i.row][i.row] = ' ';
		ft_update_mouvement(g, b, i);
		printf("d,impression d'image\n");
	}
	else
		printf("pas d,impression d'image\n");
}

void	ft_keycode_counter_handler(t_data *data, int keycode)
{
	t_xy	*begin;

	begin = &data->xy_data.begin;
	if (keycode == 65363)
		data->char_state = RIGHT;
	if (keycode == 65361)
		data->char_state = LEFT;
	if(!ft_is_keycode_in_set(keycode))
		ft_update_position(data, keycode, begin);
}

int	manage_keyboard(int keycode, t_data *data)
{
	ft_keycode_counter_handler(data, keycode);
	// if (keycode == 65307 || keycode == 64)
	// 	exit_game(data);
	return (0);
}
void	exit_game2(t_data **d)
{

	t_data *data = *d;
	printf("clean memory...\n");
	//mlx_destroy_image(data->mlx, data->img->img);
	//mlx_destroy_window(data->mlx, data->window);
	//mlx_destroy_display(data->mlx);
	//ft_free_memory(data);
	(void)data;
	printf("END GAME\n");
	exit (0);
}

int close_windows(int keycode, t_data *data)
{
    printf("voici le keycode %d\n", keycode);
	(void)data;
	
	exit_game2(&data);
    return(0);
}