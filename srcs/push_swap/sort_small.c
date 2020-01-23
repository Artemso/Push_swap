/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/23 14:20:05 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		get_minmax(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;
	t_nbr	*temp;

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
