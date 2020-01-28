/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:54:12 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 14:29:23 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	fill_image(t_prop *xt, int img_w, int img_h, int color)
{
	int count_h;
	int count_w;

	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			xt->img_data[count_h * img_w + count_w] = color;
	}
}

void		draw_stack(t_prop *xt, t_nbr *stack, int x)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		pos;

	pos = 105;
	while (stack != 0)
	{
		XT_IMG = mlx_new_image(XT_MLX, give_len(xt, stack->val), xt->width);
		XT_IDATA = (int *)mlx_get_data_addr(XT_IMG, &bpp, &size_line, &endian);
		fill_image(xt, give_len(xt, stack->val), xt->width, xt->color);
		if (stack->val > 0)
			mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, x, pos);
		else
			mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG,
				x - give_len(xt, stack->val), pos);
		mlx_destroy_image(XT_MLX, XT_IMG);
		stack = stack->next;
		pos += xt->width + 1;
	}
}

void		draw_bases(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	XT_IMG = mlx_new_image(XT_MLX, 870, 950);
	XT_IDATA = (int *)mlx_get_data_addr(XT_IMG, &bpp, &size, &endian);
	fill_image(xt, 870, 950, 0x323232);
	mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, 65, 100);
	mlx_destroy_image(XT_MLX, XT_IMG);
	mlx_string_put(XT_MLX, XT_WIN, 450, 50, 0x000000, "STACK A");
	XT_IMG = mlx_new_image(XT_MLX, 870, 950);
	XT_IDATA = (int *)mlx_get_data_addr(XT_IMG, &bpp, &size, &endian);
	fill_image(xt, 870, 950, 0x323232);
	mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, 130 + 870, 100);
	mlx_destroy_image(XT_MLX, XT_IMG);
	mlx_string_put(XT_MLX, XT_WIN, 1400, 50, 0x000000, "STACK B");
}

void		draw_background(t_prop *xt)
{
	int		bpp;
	int		size;
	int		endian;

	XT_IMG = mlx_new_image(XT_MLX, WID, HEI);
	XT_IDATA = (int *)mlx_get_data_addr(XT_IMG, &bpp, &size, &endian);
	fill_image(xt, WID, HEI, 0xFFFFFF);
	mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, 0, 0);
	mlx_destroy_image(XT_MLX, XT_IMG);
}
