/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/15 18:35:35 by solopov          ###   ########.fr       */
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
	printf("avg:%d\n", avg);
	while (cnt < len)
	{
		if (stack->val < avg)
		{
			if (stack->val + avg > prevmin + avg)
				prevmin = stack->val;
		}
		else if (stack->val > avg)
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

	get_minmax(xt, xt->stack_a);
	printf("min:%d\n", xt->min);
	printf("max:%d\n", xt->max);
	cnt = 0;
	temp = stack;
	// while (cnt < len)
	// {
	// 	if (temp->next == 0)
	// 		xt->pivot = temp->val;
	// 	temp = temp->next;
	// 	cnt++;
	// }
	find_closestval(xt->total, stack, xt);
	printf("Selected pivot:%d\n", xt->pivot);
}

static void	split_stack(t_prop *xt)
{
	int cnt;
	int moved;

	cnt = 0;
	moved = 0;
	while (cnt < xt->total)
	{
		if (xt->stack_a->val <= xt->pivot)
		{
			printf("Pushing val:%d\n", xt->stack_a->val);
			push_top(&xt->stack_a, &xt->stack_b, op_a, xt);
			moved += 1;
		}
		else
			rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	xt->elems= new_elem(moved);
	xt->elems->next = new_elem(xt->total - moved);
	print_elems(xt->elems);
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

	head = xt->elems->next;
	xt->elems = head;
}

static void	routine_a(t_prop *xt)
{
}

static void	routine_b(t_prop *xt)
{
}

void		sort_stack_quick(t_prop *xt)
{
	int cnt;

	cnt = 0;
	get_pivot_val(xt->total, xt, xt->stack_a);
	split_stack(xt);
	printf("Curr elem val:%d\n", xt->elems->val);
	printf("STACK A:\n");
	print_stack(xt->stack_a);
	printf("STACK B:\n");
	print_stack(xt->stack_b);
}
