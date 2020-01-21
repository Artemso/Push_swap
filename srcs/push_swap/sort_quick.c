/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/21 18:09:21 by asolopov         ###   ########.fr       */
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
	xt->elems = new_elem(len - moved);
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
	int		cnt;

	movmin = xt->stack_b->moves;
	posmin = 0;
	head_b = xt->stack_b;
	while (xt->stack_b != 0)
	{
		if (xt->stack_b->moves < movmin)
			posmin = xt->stack_b->pos;
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
			xt->push_data->moves = xt->stack_b->moves;
			//printf("PUSH DATA for %d: %d to_fit %d to_top %d type_a %d type_b\n", xt->stack_b->val, xt->stack_b->to_fit, xt->stack_b->to_top, xt->stack_b->type_a, xt->stack_b->type_b);
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head_b;
}

static void	push_val(t_prop *xt)
{
	int cnt;

	cnt = 0;
	if (xt->stack_b->type_a == ra && xt->stack_b->type_b == rb)
	{
		if (xt->push_data->to_top < xt->push_data->to_fit)
		{
			while (cnt < xt->push_data->to_top)
			{
				rotate_stack_two(&xt->stack_a, &xt->stack_b, xt);
				cnt++;
			}
			while (cnt < xt->push_data->to_fit)
			{
				rotate_stack(&xt->stack_a, op_a, xt);
				cnt++;
			}
			push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
		}
		else
		{
			while (cnt < xt->push_data->to_fit)
			{
				rotate_stack_two(&xt->stack_a, &xt->stack_b, xt);
				cnt++;
			}

			while (cnt < xt->push_data->to_top)
			{
				rotate_stack(&xt->stack_b, op_b, xt);
				cnt++;
			}
			push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
		}
	}
	else if (xt->stack_b->type_a == ra && xt->stack_b->type_b == rrb)
	{
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
	else if (xt->stack_b->type_a == rra && xt->stack_b->type_b == rb)
	{
		while (cnt < xt->push_data->to_top)
		{
			rrotate_stack(&xt->stack_a, op_a, xt);
			cnt++;
		}
		cnt = 0;
		while (cnt < xt->push_data->to_fit)
		{
			rotate_stack(&xt->stack_b, op_b, xt);
			cnt++;
		}
		push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
	}
	else if (xt->stack_b->type_a == rra && xt->stack_b->type_b == rrb)
	{
		if (xt->push_data->to_top < xt->push_data->to_fit)
		{
			while (cnt < xt->push_data->to_top)
			{
				rrotate_stack_two(&xt->stack_a, &xt->stack_b, xt);
				cnt++;
			}

			while (cnt < xt->push_data->to_fit)
			{
				rrotate_stack(&xt->stack_a, op_a, xt);
				cnt++;
			}
			push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
		}
		else
		{
			while (cnt < xt->push_data->to_fit)
			{
				rrotate_stack_two(&xt->stack_a, &xt->stack_b, xt);
				cnt++;
			}
			while (cnt++ < xt->push_data->to_top)
			{
				rrotate_stack(&xt->stack_b, op_b, xt);
				cnt++;
			}
			push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
		}
	}
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

static void	routine_b(t_prop *xt)
{
	int len;
	int cnt;

	len = get_len(xt->stack_b);
	cnt = 0;
	while (cnt < 7)
	{
		select_to_push(xt);
		push_val(xt);
		cnt++;
	}
	//select_to_push(xt);
	//push_val(xt);
	// while (xt->stack_b != 0)
	// {
	// 	select_to_push(xt);
	// 	push_val(xt);
	// }
	// while (len-- > 0)
	// 	rotate_stack(&xt->stack_a, op_a, xt);
}

static void	routine_a(t_prop *xt)
{
	split_stack(xt->elems->val, xt);
}


void		sort_stack_quick(t_prop *xt)
{
	split_stack(xt->total, xt);
	routine_b(xt);
	printf("STACK A:\n");
	print_stack(xt->stack_a);
	printf("STACK B:\n");
	print_stack(xt->stack_b);
	// while (!(is_sorted(xt->stack_a) == 0 && xt->stack_b == 0))
	// {
	// 	routine_b(xt);
	// 	if (xt->elems->val != 0)
	// 		routine_a(xt);
	// }
}
