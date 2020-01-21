/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/21 12:21:18 by asolopov         ###   ########.fr       */
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
	//printf("avg:%d\n", avg);
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
	if (prevmax - avg > avg - prevmin)
		xt->pivot = prevmin;
	else
		xt->pivot = prevmax;
}

static void	get_pivot_val(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;
	t_nbr	*temp;

	get_minmax(len, xt, stack);
	find_closestval(len, stack, xt);
	printf("Selected pivot:%d\n", xt->pivot);
}

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
			printf("Pushing val:%d\n", xt->stack_a->val);
			push_top(&xt->stack_a, &xt->stack_b, op_b, xt);
			moved += 1;
		}
		else
			rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	xt->elems = new_elem(len - moved);
	//print_elems(xt->elems);
}

static void	add_to_elems(int value, t_prop *xt)
{
	t_elem *head;
	t_elem *one;
	t_elem *two;

	head = xt->elems;
	one = new_elem(value);
	two = new_elem(xt->elems->val - value);
	one->next = two;
	two->next = head->next;
	xt->elems = one;
}

static void	remove_from_elems(t_prop *xt)
{
	t_elem *head;

	if (xt->elems->next != 0)
	{
		head = xt->elems->next;
		xt->elems = head;
	}
	else
		xt->elems = 0;
}

static void	routine_a(t_prop *xt)
{
	//split_stack();
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

static void	count_moves_to_top(t_prop *xt)
{
	t_nbr	*head;
	int		len;

	head = xt->stack_b;
	len = get_len(xt->stack_b);
	while (xt->stack_b != 0)
	{
		if (xt->stack_b->pos <= len / 2)
		{
			xt->stack_b->to_top = xt->stack_b->pos;
			xt->stack_b->type_b = rrb;
		}

		else
		{
			xt->stack_b->to_top = len - xt->stack_b->pos;
			xt->stack_b->type_b = rb;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head;
}

static void	count_moves_to_fit(t_prop *xt)
{
	int moves;
	t_nbr *head_a;
	t_nbr *head_b;

	head_a = xt->stack_a;
	head_b = xt->stack_b;
	get_minmax(xt->elems->val, xt, xt->stack_a);
	printf("ELEMS:\n");
	print_elems(xt->elems);
	while (xt->stack_b != 0)
	{
		moves = 0;
		xt->stack_a = head_a;
		while (xt->stack_a->next != 0)
		{
			if (xt->stack_b->val < xt->min)
				xt->stack_b->to_fit = 0;
			else if (xt->stack_b->val > xt->stack_a->val && xt->stack_b->val < xt->stack_a->next->val)
			{
				if (moves <= xt->elems->val / 2)
				{
					xt->stack_b->to_fit = moves;
					xt->stack_b->type_a = rra;
				}
				else
				{
					xt->stack_b->to_fit = xt->elems->val - moves;
					xt->stack_b->type_a = ra;
				}
			}
			xt->stack_a = xt->stack_a->next;
			moves += 1;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_a = head_a;
	xt->stack_b = head_b;
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

static void	select_to_push(t_prop *xt)
{
	int pos;

	set_positions(xt);
	count_moves_to_top(xt);
	count_moves_to_fit(xt);
	combine_moves(xt);
	compare_moves(xt);
}

static void	routine_b(t_prop *xt)
{
	int cnt;
	int rot;
	int pos;

	cnt = 0;
	select_to_push(xt);
	push(xt);
	// while (xt->stack_b != 0)
	// {
	// 	select_to_push(xt);
	// 	push(xt);
	// }
}

void		sort_stack_quick(t_prop *xt)
{
	split_stack(xt->total, xt);
	// xt->elems->val = xt->total - 1;
	// push_top(&xt->stack_a, &xt->stack_b, op_b, xt);
	routine_b(xt);
	printf("Stack A:\n");
	print_stack(xt->stack_a);
	printf("Stack B:\n");
	print_stack(xt->stack_b);
	// while (!(is_sorted(xt->stack_a) == 0 && xt->stack_b == 0))
	// {
	// 	routine_b(xt);
	// 	if (xt->elems->val != 0)
	// 		routine_a(xt);
	// }
}
