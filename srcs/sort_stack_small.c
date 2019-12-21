/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/20 11:17:47 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_nbr *head)
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

static void	sort_three(t_nbr	**stack)
{
	t_nbr	*temp;

	temp = *stack;
	while (is_sorted(temp) != 1)
	{
		if (temp->val < temp->next->val)
			swap_top(&temp);
		else
			rotate_stack(&temp);
	}
	*stack = temp;
}

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

static void	sort_four(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(xt, temp_a);
	while (temp_a->val != xt->min)
		rotate_stack(&temp_a);
	push_top(&temp_a, &temp_b);
	sort_three(&temp_a);
	push_top(&temp_b, &temp_a);
	xt->stack_a = temp_a;
}

void		sort_stack_small(t_prop *xt)
{
	if (xt->total == 3)
		sort_three(&xt->stack_a);
	else if (xt->total == 4)
		sort_four(xt);
	else if (xt->total == 5)
		sort_five(xt);
}
