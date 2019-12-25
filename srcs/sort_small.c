/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 14:08:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		get_minmax(t_prop *xt, t_nbr *stack)
{
	t_nbr *temp;

	temp = stack;
	xt->min = temp->val;
	xt->max = temp->val;
	while (temp->next != 0)
	{
		if (temp->next->val < xt->min)
			xt->min = temp->next->val;
		if (temp->next->val > xt->max)
			xt->max = temp->next->val;
		temp = temp->next;
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
		swap_top(&temp, xt);
	xt->stack_a = temp;
}

static void	sort_three(t_nbr **stack, t_prop *xt)
{
	t_nbr	*temp;

	temp = *stack;
	while (is_sorted(temp) != 1)
	{
		if (temp->val > temp->next->val &&
				temp->next->val > temp->next->next->val)
		{
			swap_top(&temp, xt);
			rrotate_stack(&temp, xt);
		}
		else if (temp->val > temp->next->val &&
				temp->val < temp->next->next->val)
			swap_top(&temp, xt);
		else if (temp->val > temp->next->val &&
				temp->next->val < temp->next->next->val)
			rotate_stack(&temp, xt);
		else if (temp->val < temp->next->val &&
				temp->val < temp->next->next->val)
		{
			swap_top(&temp, xt);
			rotate_stack(&temp, xt);
		}
		else if (temp->val < temp->next->val &&
				temp->next->val > temp->next->next->val)
			rrotate_stack(&temp, xt);
	}
	*stack = temp;
}

static void	sort_four(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(xt, temp_a);
	while (temp_a->val != xt->min)
		rotate_stack(&temp_a, xt);
	push_top(&temp_a, &temp_b, xt);
	sort_three(&temp_a, xt);
	push_top(&temp_b, &temp_a, xt);
	xt->stack_a = temp_a;
}

static void	sort_five(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(xt, temp_a);
	while (temp_a->val != xt->min)
		rotate_stack(&temp_a, xt);
	push_top(&temp_a, &temp_b, xt);
	while (temp_a->val != xt->max)
		rotate_stack(&temp_a, xt);
	push_top(&temp_a, &temp_b, xt);
	sort_three(&temp_a, xt);
	push_top(&temp_b, &temp_a, xt);
	rotate_stack(&temp_a, xt);
	push_top(&temp_b, &temp_a, xt);
	xt->stack_a = temp_a;
}

static void	sort_six(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;
	int		x;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	x = 3;
	while (x-- > 0)
		push_top(&temp_a, &temp_b, xt);
	sort_three(&temp_a, xt);
	sort_three(&temp_b, xt);
	while (get_len(temp_a) < xt->total)
	{
		if (temp_b->val > temp_a->val && temp_b->val < temp_a->next->val)
		{
			rotate_stack(&temp_a, xt);
			push_top(&temp_b, &temp_a, xt);
		}
		else if (temp_b->val < temp_a->val)
		{
			push_top(&temp_b, &temp_a, xt);
			rotate_stack(&temp_a, xt);
		}
		else if (temp_a->val == get_max(temp_a) && temp_b->val > temp_a->val)
		{
			rotate_stack(&temp_a, xt);
			push_top(&temp_b, &temp_a, xt);
		}
		else
			rotate_stack(&temp_a, xt);
	}
	while (is_sorted(temp_a) != 1)
		rotate_stack(&temp_a, xt);
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
	else if (xt->total == 6)
		sort_six(xt);
}
