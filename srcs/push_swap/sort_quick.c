/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/24 08:57:31 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	split_stack(int len, t_prop *xt)
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
			push_top(&ST_A, &ST_B, op_b, xt);
			moved += 1;
		}
		else
			rotate_stack(&ST_A, op_a, xt);
		cnt++;
	}
	xt->store = len - moved;
}

static void	set_positions(t_prop *xt)
{
	t_nbr	*head_b;
	t_nbr	*head_a;
	int		cnt;

	cnt = 0;
	head_b = ST_B;
	while (ST_B != 0)
	{
		ST_B->pos = cnt;
		cnt += 1;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
	cnt = 0;
	head_a = ST_A;
	while (ST_A != 0)
	{
		ST_A->pos = cnt;
		cnt += 1;
		ST_A = ST_A->next;
	}
	ST_A = head_a;
}

static void	combine_moves(t_prop *xt)
{
	t_nbr	*head_b;

	head_b = ST_B;
	while (ST_B != 0)
	{
		if ((ST_B->type_a == ra && ST_B->type_b == rb) || \
			(ST_B->type_a == rra && ST_B->type_b == rrb))
		{
			if (ST_B->to_top > ST_B->to_fit)
				ST_B->moves = ST_B->to_top;
			else
				ST_B->moves = ST_B->to_fit;
		}
		else if (ST_B->type_a == ra && ST_B->type_b == rrb)
			ST_B->moves = ST_B->to_top + ST_B->to_fit;
		else if (ST_B->type_a == rra && ST_B->type_b == rb)
			ST_B->moves = ST_B->to_top + ST_B->to_fit;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

static void	compare_moves(t_prop *xt)
{
	t_nbr	*head_b;
	int		movmin;
	int		posmin;

	movmin = ST_B->moves;
	posmin = 0;
	head_b = ST_B;
	while (ST_B->next != 0)
	{
		if (ST_B->next->moves < movmin)
		{
			movmin = ST_B->next->moves;
			posmin = ST_B->next->pos;
		}
		ST_B = ST_B->next;
	}
	ST_B = head_b;
	while (ST_B != 0)
	{
		if (posmin == ST_B->pos)
			ST_B->pushme = 1;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

static void	save_push_data(t_prop *xt)
{
	t_nbr	*head_b;

	head_b = ST_B;
	while (ST_B != 0)
	{
		if (ST_B->pushme == 1)
		{
			xt->push_data->to_fit = ST_B->to_fit;
			xt->push_data->to_top = ST_B->to_top;
			xt->push_data->type_a = ST_B->type_a;
			xt->push_data->type_b = ST_B->type_b;
		}
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

static void	push_val(t_prop *xt)
{
	if (xt->push_data->type_a == ra && xt->push_data->type_b == rb)
		ra_rb(xt);
	else if (xt->push_data->type_a == ra && xt->push_data->type_b == rrb)
		ra_rrb(xt);
	else if (xt->push_data->type_a == rra && xt->push_data->type_b == rb)
		rra_rb(xt);
	else if (xt->push_data->type_a == rra && xt->push_data->type_b == rrb)
		rra_rrb(xt);
}

static void	select_to_push(t_prop *xt)
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

static int	get_n_pos(int nb, t_nbr *stack)
{
	int	pos;

	pos = 0;
	while (stack != 0)
	{
		if (stack->val == nb)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

static void	routine_b(t_prop *xt)
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
	{
		while (cnt < pos + 1)
		{
			rotate_stack(&ST_A, op_a, xt);
			cnt++;
		}
	} // maybe separate this
	else
	{
		while (cnt < len - pos - 1)
		{
			rrotate_stack(&ST_A, op_a, xt);
			cnt++;
		}
	} // maybe separate this
}

static void	routine_b_med(t_prop *xt)
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
	{
		while (cnt < pos + 1)
		{
			rotate_stack(&ST_A, op_a, xt);
			cnt++;
		} // maybe separate this
	}
	else
	{
		while (cnt < len - pos - 1)
		{
			rrotate_stack(&ST_A, op_a, xt);
			cnt++;
		} // maybe separate this
	}
}

static void	routine_a(t_prop *xt)
{
	if (xt->store > 100)
		split_stack(xt->store, xt);
	else
	{
		while (xt->store > 0)
		{
			push_top(&ST_A, &ST_B, op_b, xt);
			xt->store -= 1;
		}
	}
}

void		sort_stack_quick(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->total > 250)
	{
		split_stack(xt->total, xt);
		while (!(is_sorted(ST_A) == 1 && ST_B == 0))
		{
			routine_b(xt);
			if (xt->store != 0)
				routine_a(xt);
		}
	} //sort 250
	else
	{
		while (cnt < xt->total - 3)
		{
			push_top(&ST_A, &ST_B, op_b, xt);
			cnt++;
		}
		if (get_len(ST_A) == 3)
			sort_three(&ST_A, xt);
		routine_b_med(xt);
	} //sort smaller
	free_mem(xt);
}
