/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:35:55 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 14:02:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

int		draw_one(t_prop *xt)
{
	int		ret;
	char	*line;

	if (xt->pause == 1)
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
	draw_stack(xt, xt->stack_b, 1425);
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
