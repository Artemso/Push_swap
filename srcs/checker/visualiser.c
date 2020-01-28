/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:35:55 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 13:22:05 by asolopov         ###   ########.fr       */
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

static void	draw_background(t_prop *xt)
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

static void	draw_bases(t_prop *xt)
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

int		get_len(t_nbr *stack)
{
	int	ret;

	ret = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		ret++;
	}
	return (ret);
}

int		get_max(t_nbr *stack)
{
	int		max;

	max = stack->val;
	while (stack->next != 0)
	{
		if (stack->next->val > max)
			max = stack->next->val;
		stack = stack->next;
	}
	return (max);
}

int		give_len(t_prop *xt, int val)
{
	float	num;
	int		len;

	num = (float)xt->max_val / (float)val;
	len = (435 - 20) / num;
	if (len < 0)
		len *= -1;
	return (len);
}

void	draw_stack(t_prop *xt, t_nbr *stack, int x)
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
		fill_image(xt, give_len(xt, stack->val), xt->width, 0xFF3232);
		if (stack->val > 0)
			mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, x, pos);
		else
			mlx_put_image_to_window(XT_MLX, XT_WIN, XT_IMG, x - give_len(xt, stack->val), pos);
		mlx_destroy_image(XT_MLX, XT_IMG);
		stack = stack->next;
		pos += xt->width + 1;
	}
}

static void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "Push_Swap");
}

void	get_width_max(t_prop *xt)
{
	xt->width = (870 - get_len(xt->stack_a)) / get_len(xt->stack_a);
	if (xt->width == 0)
		xt->width = 1;
	xt->max_val = get_max(xt->stack_a);
}

void	redraw(t_prop *xt)
{
	mlx_clear_window(xt->mlx_ptr, xt->win_ptr);
	draw_background(xt);
	draw_bases(xt);
	draw_stack(xt, xt->stack_a, 500);
	draw_stack(xt, xt->stack_b, 1425);
}



int		onupdate(t_prop *xt)
{
	int		ret;
	char	*line;
	if (xt->pause == 0)
	{
		if ((ret = get_next_line(0, &line)) > 0)
		{
			apply_instruction(line, xt);
			free(line);
		}
		redraw(xt);
	}
	return (0);
}

void	draw_all(t_prop *xt)
{
	draw_background(xt);
	draw_bases(xt);
	draw_stack(xt, xt->stack_a, 500);
	draw_stack(xt, xt->stack_b, 1305);
	mlx_hook(xt->win_ptr, 2, 0, key_hook_press, xt);
	mlx_loop_hook(XT_MLX, &onupdate, xt);
	mlx_loop(xt->mlx_ptr);
}

void	visualise(t_prop *xt)
{
	if (get_len(xt->stack_a) < 451)
	{
		init_window(xt);
		get_width_max(xt);
		draw_all(xt);
	}
	else
		ft_puterr(er_max);
}
