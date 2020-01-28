/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 12:22:15 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 14:00:43 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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
