/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 15:20:04 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		split_stack(int len, t_prop *xt)
{
	int cnt;
	int moved;

	cnt = 0;
	moved = 0;
	get_pivot_val(len, xt, ST_A);
	while (cnt < len)
	{
		if (ST_A->val < xt->pivot)
		{
			push_top(&ST_A, &ST_B, op_b);
			moved += 1;
		}
		else
			rotate_stack(&ST_A, op_a);
		cnt++;
	}
	xt->store = len - moved;
}

void		select_to_push(t_prop *xt)
{
	int	len_a;
	int	len_b;

	len_a = get_len(ST_A);
	len_b = get_len(ST_B);
	set_positions(xt);
	count_moves_to_top(len_b, xt);
	count_moves_to_fit(len_a, xt);
	combine_moves(xt);
	compare_moves(xt);
	save_push_data(xt);
}

void		sort_split(t_prop *xt)
{
	split_stack(xt->total, xt);
	while (!(is_sorted(ST_A) == 1 && ST_B == 0))
	{
		routine_b_split(xt);
		if (xt->store != 0)
			routine_a(xt);
	}
}

void		sort_stack_quick(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->total > 250)
		sort_split(xt);
	else if (xt->total == 2)
		sort_two(&ST_A);
	else if (xt->total > 2)
	{
		while (cnt < xt->total - 3)
		{
			push_top(&ST_A, &ST_B, op_b);
			cnt++;
		}
		sort_three(&ST_A);
		routine_b_nosplit(xt);
	}
	free_mem(xt);
}
