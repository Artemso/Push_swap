/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:29:15 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:45:44 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_ra_rb_totop(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rotate_stack_2(&ST_A, &ST_B);
		cnt++;
	}
	while (cnt < xt->push_data->to_fit)
	{
		rotate_stack(&ST_A, op_a);
		cnt++;
	}
}

void	rotate_ra_rb_tofit(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rotate_stack_2(&ST_A, &ST_B);
		cnt++;
	}
	while (cnt < xt->push_data->to_top)
	{
		rotate_stack(&ST_B, op_b);
		cnt++;
	}
}

void	rotate_rra_rrb_totop(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rrotate_stack_2(&ST_A, &ST_B);
		cnt++;
	}
	while (cnt < xt->push_data->to_fit)
	{
		rrotate_stack(&ST_A, op_a);
		cnt++;
	}
}

void	rotate_rra_rrb_tofit(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rrotate_stack_2(&ST_A, &ST_B);
		cnt++;
	}
	while (cnt < xt->push_data->to_top)
	{
		rrotate_stack(&ST_B, op_b);
		cnt++;
	}
}
