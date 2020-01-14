/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:39:19 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/14 17:49:23 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	get_pivot_val(t_prop *xt, t_nbr *stack)
{
	t_nbr	*temp;

	temp = stack;
	while (temp != 0)
	{
		if (temp->next == 0)
			xt->pivot = temp->val;
		temp = temp->next;
	}
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
			push_top(&xt->stack_a, &xt->stack_b, op_a, xt);
			moved += 1;
		}
		else
			rotate_stack(&xt->stack_a, op_a, xt);
		cnt++;
	}
	xt->elems->val = moved;
	xt->elems->next->val = xt->total - moved;
	print_elems(xt->elems);
}

static void	routine_a(t_prop *xt)
{
	int cnt;

	cnt = 0;
	while (cnt < xt->elems->val)
		push_top(&xt->stack_a, &xt->stack_b, op_a, xt);
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

// static void	routine_b(t_prop *xt)
// {
// 	int	cnt;
// 	int len;

// 	cnt = 0;
// 	len = get_len(xt->stack_b);
// 	get_pivot_val(xt, xt->stack_b);
// 	while (cnt < len)
// 	{
// 		if (xt->stack_b->val > xt->pivot)
// 			split_send_right_to_a(); // modify number of elements in int array
// 		cnt++;
// 	}
// }

void		sort_stack_quick(t_prop *xt)
{
	get_pivot_val(xt, xt->stack_a);
	split_stack(xt);
	// while (!(is_sorted(xt->stack_a) && xt->stack_b == 0))
	// {
	// 	if (xt->elems[0] <= 3)
	// 	{
	// 		insert_sort_to_a(xt);
	// 		rotate_a(xt);
	// 	}
	// 	while (xt->elems[0] > 3)
	// 		routine_b(xt);
	// 	routine_a(xt);
	// }
}
