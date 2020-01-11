/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:42:20 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/11 13:11:53 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "Push_Swap");
}

static char *fill_image(t_prop *xt)
{
	int count_h;
	int count_w;
	int img_h;
	int img_w;

	img_w = xt->stack_a->val * 10;
	img_h = 10;
	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			xt->img_data[count_h * img_w + count_w] = 0xFFFFFF;
	}
}

int			expose_hook(t_prop *xt)
{
	int		bpp;
	int		size_line;
	int		endian;

	xt->img_ptr = mlx_new_image(xt->mlx_ptr, xt->stack_a->val * 10, 10);
	xt->img_data = mlx_get_data_addr(xt->img_ptr, &bpp, &size_line, &endian);
	fill_image(xt);
	mlx_put_image_to_window(xt->mlx_ptr, xt->win_ptr, xt->img_ptr, 20, 10);
}

void		visualise(t_prop *xt)
{
	init_window(xt);
	mlx_expose_hook(xt->win_ptr, expose_hook, xt);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(xt->mlx_ptr);
}
