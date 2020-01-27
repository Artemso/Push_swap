/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:23 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 14:06:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	routine_b_nosplit(t_prop *xt)
{
	int cnt;
	int	max_a;
	int	pos;
	int	len;

	cnt = 0;
	while (ST_B != 0)
	{
		select_to_push(xt);
		push_val(xt);
	}
	max_a = get_max(ST_A);
	len = get_len(ST_A);
	pos = get_n_pos(max_a, ST_A);
	if (pos <= len / 2)
		do_rotate(cnt, pos, xt);
	else
		do_rrotate(cnt, len, pos, xt);
}

void	routine_b_split(t_prop *xt)
{
	int cnt;
	int	max_b;
	int	pos;
	int	len;

	max_b = get_max(ST_B);
	cnt = 0;
	while (ST_B != 0)
	{
		select_to_push(xt);
		push_val(xt);
	}
	len = get_len(ST_A);
	pos = get_n_pos(max_b, ST_A);
	if (pos <= len / 2)
		do_rotate(cnt, pos, xt);
	else
		do_rrotate(cnt, len, pos, xt);
}

void	routine_a(t_prop *xt)
{
	if (xt->store > 100)
		split_stack(xt->store, xt);
	else
	{
		while (xt->store > 0)
		{
			push_top(&ST_A, &ST_B, op_b);
			xt->store -= 1;
		}
	}
}
