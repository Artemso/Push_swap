/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:18:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:39:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_closestval(int len, t_nbr *stack, t_prop *xt)
{
	int cnt;
	int avg;
	int prevmax;
	int prevmin;

	prevmin = xt->min;
	prevmax = xt->max;
	cnt = 0;
	avg = (xt->max + xt->min) / 2;
	while (cnt < len)
	{
		if (stack->val < avg)
		{
			if (stack->val + avg > prevmin + avg)
				prevmin = stack->val;
		}
		else if (stack->val >= avg)
		{
			if (stack->val - avg < prevmax - avg)
				prevmax = stack->val;
		}
		stack = stack->next;
		cnt++;
	}
	xt->pivot = (prevmax - avg > avg - prevmin) ? prevmin : prevmax;
}

void		get_pivot_val(int len, t_prop *xt, t_nbr *stack)
{
	get_minmax(len, xt, stack);
	find_closestval(len, stack, xt);
}
