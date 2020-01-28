/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:52:13 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 15:20:01 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

void	get_minmax(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;

	cnt = 0;
	xt->min = stack->val;
	xt->max = stack->val;
	while (cnt < len - 1)
	{
		if (stack->next->val < xt->min)
			xt->min = stack->next->val;
		if (stack->next->val > xt->max)
			xt->max = stack->next->val;
		stack = stack->next;
		cnt += 1;
	}
}

int		give_len(t_prop *xt, int val)
{
	float	num;
	int		len;

	if (xt->min < 0)
		xt->min *= -1;
	if (xt->min > xt->max)
		num = (float)xt->min / (float)val;
	else
		num = (float)xt->max / (float)val;
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
}

void	init_window(t_prop *xt)
{
	xt->mlx_ptr = mlx_init();
	xt->win_ptr = mlx_new_window(xt->mlx_ptr, 1920, 1080, "Push_Swap");
}
