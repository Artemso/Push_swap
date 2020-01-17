/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/17 17:34:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		get_minmax(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;
	t_nbr *temp;

	cnt = 0;
	temp = stack;
	xt->min = temp->val;
	xt->max = temp->val;
	while (cnt < len - 1)
	{
		if (temp->next->val < xt->min)
			xt->min = temp->next->val;
		if (temp->next->val > xt->max)
			xt->max = temp->next->val;
		temp = temp->next;
		cnt += 1;
	}
}

int	is_sorted(t_nbr *head)
{
	t_nbr *temp;

	temp = head;
	while (temp->next != 0)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	sort_two(t_nbr **stack, t_prop *xt)
{
	t_nbr	*temp;

	temp = *stack;
	if (is_sorted(temp) != 1)
		swap_top(&temp, op_a, xt);
	xt->stack_a = temp;
}

void	sort_three(t_nbr **stack, t_prop *xt)
{
	t_nbr	*temp;

	temp = *stack;
	while (is_sorted(temp) != 1)
	{
		if (temp->val > temp->next->val &&
				temp->next->val > temp->next->next->val)
		{
			swap_top(&temp, op_a, xt);
			rrotate_stack(&temp, op_a, xt);
		}
		else if (temp->val > temp->next->val &&
				temp->val < temp->next->next->val)
			swap_top(&temp, op_a, xt);
		else if (temp->val > temp->next->val &&
				temp->next->val < temp->next->next->val)
			rotate_stack(&temp, op_a, xt);
		else if (temp->val < temp->next->val &&
				temp->val < temp->next->next->val)
		{
			swap_top(&temp, op_a, xt);
			rotate_stack(&temp, op_a, xt);
		}
		else if (temp->val < temp->next->val &&
				temp->next->val > temp->next->next->val)
			rrotate_stack(&temp, op_a, xt);
	}
	*stack = temp;
}

static void	sort_four(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(get_len(temp_a), xt, temp_a);
	while (temp_a->val != xt->min)
		rotate_stack(&temp_a, op_a, xt);
	push_top(&temp_a, &temp_b, op_a, xt);
	sort_three(&temp_a, xt);
	push_top(&temp_b, &temp_a, op_b, xt);
	xt->stack_a = temp_a;
}

static void	sort_five(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(get_len(temp_a), xt, temp_a);
	while (temp_a->val != xt->min)
		rotate_stack(&temp_a, op_a, xt);
	push_top(&temp_a, &temp_b, op_a, xt);
	while (temp_a->val != xt->max)
		rotate_stack(&temp_a, op_a, xt);
	push_top(&temp_a, &temp_b, op_a, xt);
	sort_three(&temp_a, xt);
	push_top(&temp_b, &temp_a, op_b, xt);
	rotate_stack(&temp_a, op_a, xt);
	push_top(&temp_b, &temp_a, op_b, xt);
	xt->stack_a = temp_a;
}

void		sort_stack_small(t_prop *xt)
{
	if (xt->total == 2)
		sort_two(&xt->stack_a, xt);
	if (xt->total == 3)
		sort_three(&xt->stack_a, xt);
	else if (xt->total == 4)
		sort_four(xt);
	else if (xt->total == 5)
		sort_five(xt);
}
