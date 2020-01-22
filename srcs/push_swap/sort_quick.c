/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/22 14:07:00 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	split_stack(int len, t_prop *xt)
{
	int cnt;
	int moved;

	cnt = 0;
	moved = 0;
	get_pivot_val(len, xt, xt->stack_a);
	while (cnt < len)
	{
		if (xt->stack_a->val < xt->pivot)
		{
			push_top(&xt->stack_a, &xt->stack_b, op_b, xt);
			moved += 1;
		}
		else
			rotate_stack(&xt->stack_a, op_a, xt);
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
	head_b = xt->stack_b;
	while (xt->stack_b != 0)
	{
		xt->stack_b->pos = cnt;
		cnt += 1;
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
	cnt = 0;
	head_a = xt->stack_a;
	while (xt->stack_a != 0)
	{
		xt->stack_a->pos = cnt;
		cnt += 1;
		xt->stack_a = xt->stack_a->next;
	}
	xt->stack_a = head_a;
}

static void	combine_moves(t_prop *xt)
{
	t_nbr	*head_b;

	head_b = xt->stack_b;
	while (xt->stack_b != 0)
	{
		if (xt->stack_b->type_a == ra && xt->stack_b->type_b == rb)
		{
			if (xt->stack_b->to_top > xt->stack_b->to_fit)
				xt->stack_b->moves = xt->stack_b->to_top;
			else
				xt->stack_b->moves = xt->stack_b->to_fit;
		}
		else if (xt->stack_b->type_a == ra && xt->stack_b->type_b == rrb)
		{
			xt->stack_b->moves = xt->stack_b->to_top + xt->stack_b->to_fit;
		}
		else if (xt->stack_b->type_a == rra && xt->stack_b->type_b == rb)
		{
			xt->stack_b->moves = xt->stack_b->to_top + xt->stack_b->to_fit;
		}
		else if (xt->stack_b->type_a == rra && xt->stack_b->type_b == rrb)
		{
			if (xt->stack_b->to_top > xt->stack_b->to_fit)
				xt->stack_b->moves = xt->stack_b->to_top;
			else
				xt->stack_b->moves = xt->stack_b->to_fit;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
}

static void	compare_moves(t_prop *xt)
{
	t_nbr	*head_b;
	int		movmin;
	int		posmin;

	movmin = xt->stack_b->moves;
	posmin = 0;
	head_b = xt->stack_b;
	while (xt->stack_b->next != 0)
	{
		if (xt->stack_b->next->moves < movmin)
		{
			movmin = xt->stack_b->next->moves;
			posmin = xt->stack_b->next->pos;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
	while (xt->stack_b != 0)
	{
		if (posmin == xt->stack_b->pos)
			xt->stack_b->pushme = 1;
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
}

static void	save_push_data(t_prop *xt)
{
	t_nbr	*head_b;

	xt->push_data = malloc(sizeof(t_push));
	head_b = xt->stack_b;
	while (xt->stack_b != 0)
	{
		if (xt->stack_b->pushme == 1)
		{
			xt->push_data->to_fit = xt->stack_b->to_fit;
			xt->push_data->to_top = xt->stack_b->to_top;
			xt->push_data->type_a = xt->stack_b->type_a;
			xt->push_data->type_b = xt->stack_b->type_b;
			//printf("PUSH DATA for %d: %d to_fit %d to_top %d type_a %d type_b\n", xt->stack_b->val, xt->stack_b->to_fit, xt->stack_b->to_top, xt->stack_b->type_a, xt->stack_b->type_b);
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
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
	int pos;

	set_positions(xt);
	count_moves_to_top(xt);
	count_moves_to_fit(xt);
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

	max_b = get_max(xt->stack_b);
	cnt = 0;
	while (xt->stack_b != 0)
	{
		select_to_push(xt);
		push_val(xt);
	}
	pos = get_n_pos(max_b, xt->stack_a);
	while (cnt < pos + 1)
	{
		rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
}

static void	routine_a(t_prop *xt)
{
	if (xt->store > 20)
		split_stack(xt->store, xt);
	else
	{
		while (xt->store > 0)
		{
			push_top(&xt->stack_a, &xt->stack_b, op_b, xt);
			xt->store -= 1;
		}
	}
}

void		sort_stack_quick(t_prop *xt)
{
	split_stack(xt->total, xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// push_val(xt);
	// select_to_push(xt);
	// printf("STACK_A:\n");
	// print_stack(xt->stack_a);
	// printf("STACK_B:\n");
	// print_stack(xt->stack_b);
	while (!(is_sorted(xt->stack_a) == 1 && xt->stack_b == 0))
	{
		routine_b(xt);
		if (xt->store != 0)
			routine_a(xt);
	}
}
