/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:22:15 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 13:06:07 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	draw_one(t_prop *xt)
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

int	key_hook_press(int keycode, t_prop *xt)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 49 && xt->pause == 1)
		xt->pause = 0;
	else if (keycode == 49 && xt->pause == 0)
		xt->pause = 1;
	else if (keycode == 124)
		draw_one(xt);
	return (0);
}
