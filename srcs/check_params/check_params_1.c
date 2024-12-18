/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:33 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/18 13:06:07 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_params(char **map, int hauteur, int largeur)
{
	if (is_rectangle(hauteur, largeur) || are_exit(map, hauteur, largeur))
		return (1);
	if (are_item(map, hauteur, largeur) || are_start(map, hauteur, largeur))
		return (1);
	if (is_close(map, hauteur, largeur))
		return (1);
	return (0);
}
