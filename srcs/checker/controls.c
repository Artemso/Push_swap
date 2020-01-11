/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:22:15 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/11 15:33:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	key_hook_press(int keycode, t_prop *xt)
{
	char	*line;
	int		y;
	
	if (keycode == 53)
		exit(1);
	if (keycode == 124)
	{
		y = get_next_line(0, &line);
		if (y != 0)
		{
			mlx_clear_window(xt->mlx_ptr, xt->win_ptr);
			apply_instruction(line, xt);
			draw_stack(xt, xt->stack_a);
			draw_stack_2(xt, xt->stack_b);
			free(line);
		}
	}
	return (0);
}
