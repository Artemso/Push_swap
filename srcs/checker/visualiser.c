/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:42:20 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/11 15:36:11 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void		print_stack(t_nbr *stack)
{
	t_nbr *temp;

	temp = stack;
	while (temp != 0)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

static void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "Push_Swap");
}

static void	fill_image(t_prop *xt, t_nbr *stack)
{
	int count_h;
	int count_w;
	int img_h;
	int img_w;

	img_w = stack->val * 2;
	img_h = 10;
	count_h = -1;
	while (++count_h < img_h)
	{
		count_w = -1;
		while (++count_w < img_w)
			xt->img_data[count_h * img_w + count_w] = 0xFFFFFF;
	}
}

int			draw_stack(t_prop *xt, t_nbr *stack)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		pos;
	t_nbr	*temp;

	temp = stack;
	pos = 100;
	while (temp != 0)
	{
		xt->img_ptr = mlx_new_image(xt->mlx_ptr, temp->val * 2, 10);
		xt->img_data = (int *)mlx_get_data_addr(xt->img_ptr, &bpp, &size_line, &endian);
		fill_image(xt, temp);
		mlx_put_image_to_window(xt->mlx_ptr, xt->win_ptr, xt->img_ptr, 20, pos);
		temp = temp->next;
		pos += 100;
	}
	return (0);
}

int			draw_stack_2(t_prop *xt, t_nbr *stack)
{
	int		bpp;
	int		size_line;
	int		endian;
	int		pos;
	t_nbr	*temp;

	temp = stack;
	pos = 100;
	while (temp != 0)
	{
		xt->img_ptr = mlx_new_image(xt->mlx_ptr, temp->val * 2, 10);
		xt->img_data = (int *)mlx_get_data_addr(xt->img_ptr, &bpp, &size_line, &endian);
		fill_image(xt, temp);
		mlx_put_image_to_window(xt->mlx_ptr, xt->win_ptr, xt->img_ptr, 1000, pos);
		temp = temp->next;
		pos += 100;
	}
	return (0);
}

void		visualise(t_prop *xt)
{
	char	*line;
	int		y;

	init_window(xt);
	draw_stack(xt, xt->stack_a);
	draw_stack_2(xt, xt->stack_b);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop(xt->mlx_ptr);
}
