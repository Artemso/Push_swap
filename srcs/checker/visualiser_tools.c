/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:52:13 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 13:55:59 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

int		give_len(t_prop *xt, int val)
{
	float	num;
	int		len;

	if (val < 0)
		num = (float)xt->max_val / (float)val * 2;
	else
		num = (float)xt->max_val / (float)val;
	len = (435 - 20) / num;
	if (len < 0)
		len *= -1;
	return (len);
}

void	get_width_max(t_prop *xt)
{
	xt->width = (870 - get_len(xt->stack_a)) / get_len(xt->stack_a);
	if (xt->width == 0)
		xt->width = 1;
	xt->max_val = get_max(xt->stack_a);
}

void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "Push_Swap");
}
