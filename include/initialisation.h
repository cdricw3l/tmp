/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cb <cb@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:13:54 by cb                #+#    #+#             */
/*   Updated: 2025/01/09 17:04:24 by cb               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INITIALISATION_H
#define INITIALISATION_H

#include "so_long.h"

typedef struct s_data t_data;


t_data  *initialisation_and_check(char *path);
t_data	*data_initialisation(char *map_path);
char	**get_map(t_data *data);
int     check_map(t_data *data);
int     check_valide_way(t_data *data);


#endif