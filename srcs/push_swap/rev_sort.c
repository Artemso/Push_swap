/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:29:43 by solopov           #+#    #+#             */
/*   Updated: 2020/01/17 12:36:44 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max_2(t_prop *xt, t_nbr *stack)
{
	t_nbr	*temp;
	int		pos;

	temp = stack;
	xt->max = temp->val;
	pos = 0;
	while (temp->next != 0)
	{
		if (temp->next->val > xt->max)
			xt->max = temp->next->val;
		temp = temp->next;
		pos += 1;
	}
	return (pos);
}

void		rev_sort_stack(t_prop *xt)
{
	int pos;

	while (xt->stack_b != 0)
	{
		pos = get_max_2(xt, xt->stack_b);
		if (xt->stack_b->val == xt->max)
			push_top(&xt->stack_b, &xt->stack_a, op_a, xt);
		else
		{
			if (pos >= get_len(xt->stack_b) / 2)
				rrotate_stack(&xt->stack_b, op_b, xt);
			else
				rotate_stack(&xt->stack_b, op_b, xt);
		}
	}
}
