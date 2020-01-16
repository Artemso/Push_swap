/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/16 16:19:11 by solopov          ###   ########.fr       */
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

	get_minmax(xt, stack);
	// printf("min:%d\n", xt->min);
	// printf("max:%d\n", xt->max);
	cnt = 0;
	// temp = stack;
	// while (cnt < len)
	// {
	// 	if (temp->next == 0)
	// 		xt->pivot = temp->val;
	// 	temp = temp->next;
	// 	cnt++;
	// }
	find_closestval(len, stack, xt);
	//printf("Selected pivot:%d\n", xt->pivot);
}

static void	split_stack(t_prop *xt)
{
	int cnt;
	int moved;

	cnt = 0;
	moved = 0;
	while (cnt < xt->total)
	{
		if (xt->stack_a->val < xt->pivot)
		{
			//printf("Pushing val:%d\n", xt->stack_a->val);
			push_top(&xt->stack_a, &xt->stack_b, op_a, xt);
			moved += 1;
		}
		else
			rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	xt->elems= new_elem(moved);
	xt->elems->next = new_elem(xt->total - moved);
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
	int cnt;

	cnt = 0;
	while (cnt < xt->elems->val)
	{
		push_top(&xt->stack_a, &xt->stack_b, op_a, xt);
		cnt++;
	}
}

static void	routine_b(t_prop *xt)
{
	int cnt;
	int sent;

	cnt = 0;
	sent = 0;
	while (xt->stack_b != 0)
	{
		if (get_len(xt->stack_b) > 3)
		{
			get_pivot_val(xt->elems->val, xt, xt->stack_b);
			while (cnt < xt->elems->val)
			{
				if (xt->stack_b->val > xt->pivot)
				{
					push_top(&xt->stack_b, &xt->stack_a, op_b, xt);
					sent++;
				}
				else
					rotate_stack(&xt->stack_b, op_b, xt);
				cnt++;
			}
			cnt = 0;
			add_to_elems(xt->elems->val - sent, xt);
			sent = 0;
		}
		if (get_len(xt->stack_b) <= 10 && xt->stack_b != 0)
		{
			cnt = 0;
			// printf("STACK B:");
			// print_stack(xt->stack_b);
			rev_sort_stack(xt);
			// while (cnt++ < xt->elems->val)
			// 	push_top(&xt->stack_b, &xt->stack_a, op_b, xt);
			cnt = 0;
			while (cnt++ < xt->elems->val)
				rotate_stack(&xt->stack_a, op_a, xt);
			remove_from_elems(xt);
		}
	}
}

void		sort_stack_quick(t_prop *xt)
{
	int cnt;

	cnt = 0;
	get_pivot_val(xt->total, xt, xt->stack_a);
	split_stack(xt);
	while (!(is_sorted(xt->stack_a) == 1 && xt->stack_b == 0))
	{
		routine_b(xt);
		if (xt->elems != 0)
			routine_a(xt);
	}
	// routine_b(xt);
	// routine_a(xt);
	// routine_b(xt);
	// routine_a(xt);
	// routine_b(xt);
	// routine_a(xt);
	// routine_b(xt);
	// printf("ELEM LIST:");
	// print_elems(xt->elems);
	printf("STACK A:\n");
	print_stack(xt->stack_a);
	printf("STACK B:\n");
	print_stack(xt->stack_b);
}
