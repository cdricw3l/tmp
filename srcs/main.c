/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:40:59 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/12/17 14:55:35 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bit_per_pixel;
    int     line_length;
    int     endian;



} t_data;


void ft_put_px(t_data *data, int x, int y, int color)
{
    char *dst;


    dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
    *(unsigned int *)dst = color;
}


int	main(void)
{
    void	*mlx;
    void    *new_w;
    t_data  img;


    mlx = mlx_init();
    new_w = mlx_new_window(mlx, 1920, 1080, "hello");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_length, &img.endian);
    ft_put_px(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, new_w, img.img, 0, 0);

    mlx_loop(mlx);

    return(0);
}


//valgrind --leak-check=yes myprog arg1 arg2