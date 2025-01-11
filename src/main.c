// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cbouhadr <cbouhadr@student.42.fr>                      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/01/05 14:56:23 by cb                #+#    #+#             */
// /*   Updated: 2025/01/05 14:56:24 by cb               ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../include/so_long.h"

void    start_game(t_data **data)
{

	(*data)->mlx = mlx_init();
	mlx_get_screen_size((*data)->mlx, &(*data)->xy_data.screen_size.col, &(*data)->xy_data.screen_size.row);
    (*data)->window = mlx_new_window((*data)->mlx, TILD_SIZE * (*data)->xy_data.map.col, TILD_SIZE * (*data)->xy_data.map.row, "hello");
    if(!(*data)->window || !(*data)->mlx)
    {
        return ;
    }

	// while (1)
	// {
	// 	if(char_layer(*data,0) == NULL)
	// 		return ;
	// 	/* code */
	// }
	
    mlx_hook((*data)->window, 2, 1L<<0 ,manage_keyboard, (*data));
    printf("adresse 1: %p et adresse 2: %p\n", (*data)->mlx, (*data)->window);
   	mlx_hook((*data)->window, 17, 1L<<0 ,close_windows, (*data));
    mlx_loop((*data)->mlx) ;
}

	
int	main(int argc, char *argv[])
{
	t_data		*data;

	if (argc != 2)
		return (error_layer(0));
	else
	{
		data = initialisation_and_check(argv[1]);
		if (!data)
			return (1);
		ft_display_data_info(data); // a suuprimmer pour le rendu
		start_game(&data);
		printf("liberation de la memoire\n");
		free_memory(&data, 1);
		
	}
	return (0);
}
