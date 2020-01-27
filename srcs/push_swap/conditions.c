/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:55:42 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 12:57:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ra_rb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->push_data->to_top < xt->push_data->to_fit)
	{
		while (cnt < xt->push_data->to_top)
		{
			rotate_stack_2(&xt->stack_a, &xt->stack_b, xt);
			cnt++;
		}
		while (cnt < xt->push_data->to_fit)
		{
			rotate_stack(&xt->stack_a, op_a, xt);
			cnt++;
		}
	}
	else
	{
		while (cnt < xt->push_data->to_fit)
		{
			rotate_stack_2(&xt->stack_a, &xt->stack_b, xt);
			cnt++;
		}
		while (cnt < xt->push_data->to_top)
		{
			rotate_stack(&xt->stack_b, op_b, xt);
			cnt++;
		}
	}
	push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
}

void	ra_rrb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rrotate_stack(&xt->stack_b, op_b, xt);
		cnt++;
	}
	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
}

void	rra_rb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rotate_stack(&xt->stack_b, op_b, xt);
		cnt++;
	}
	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rrotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
}

void	rra_rrb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->push_data->to_top < xt->push_data->to_fit)
	{
		while (cnt < xt->push_data->to_top)
		{
			rrotate_stack_2(&xt->stack_a, &xt->stack_b, xt);
			cnt++;
		}
		while (cnt < xt->push_data->to_fit)
		{
			rrotate_stack(&xt->stack_a, op_a, xt);
			cnt++;
		}
	}
	else
	{
		while (cnt < xt->push_data->to_fit)
		{
			rrotate_stack_2(&xt->stack_a, &xt->stack_b, xt);
			cnt++;
		}
		while (cnt < xt->push_data->to_top)
		{
			rrotate_stack(&xt->stack_b, op_b, xt);
			cnt++;
		}
	}
	push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
}
