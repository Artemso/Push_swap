/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:55:42 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:43:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra_rb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->push_data->to_top < xt->push_data->to_fit)
		rotate_ra_rb_totop(xt);
	else
		rotate_ra_rb_tofit(xt);
	push_top(&ST_B, &ST_A, op_a);
}

void	ra_rrb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rrotate_stack(&ST_B, op_b);
		cnt++;
	}
	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rotate_stack(&ST_A, op_a);
		cnt++;
	}
	push_top(&ST_B, &ST_A, op_a);
}

void	rra_rb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->push_data->to_top)
	{
		rotate_stack(&ST_B, op_b);
		cnt++;
	}
	cnt = 0;
	while (cnt < xt->push_data->to_fit)
	{
		rrotate_stack(&ST_A, op_a);
		cnt++;
	}
	push_top(&ST_B, &ST_A, op_a);
}

void	rra_rrb(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->push_data->to_top < xt->push_data->to_fit)
		rotate_rra_rrb_totop(xt);
	else
		rotate_rra_rrb_tofit(xt);
	push_top(&ST_B, &ST_A, op_a);
}
