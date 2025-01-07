/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_image_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:23:15 by cb                #+#    #+#             */
/*   Updated: 2025/01/07 14:28:38 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	image_loader(char **path, t_data *data)
{
	int	i;
	t_img **img;

	i = 0;
	img = data->img_set;
	while (i < IMG_SET_SIZE)
	{	
		img[i]->img = mlx_xpm_file_to_image(data->mlx, path[i],
					&(img[i]->width), &(img[i]->height));
		printf("creation de la image %p\n",img[i]);
		if (!img[i]->img)
			return (1);
		img[i]->position = i;
		i++;
	}
	PRINT("END CREAT IMAGE");
	return (0);
}