/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 16:20:33 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MEMORY_MANAGMENT_H
#define MEMORY_MANAGMENT_H

#include "so_long.h"

typedef struct s_data t_data;
typedef struct s_img t_img;
typedef struct s_img_sets t_img_sets;

int     clean_image_memory(t_data **d, t_img_sets **data, int index);
void    *free_memory(t_data **data, int err);
void	free_path_memory(char **path_g, char **path_l, char **path_r);
int     error_layer(int err);

#endif