/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:29:43 by solopov           #+#    #+#             */
/*   Updated: 2020/01/16 16:00:12 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_max_2(t_nbr *stack)
{
	t_nbr	*temp;
	int		max;

	temp = stack;
	max = temp->val;
	while (temp->next != 0)
	{
		if (temp->next->val > max)
			max = temp->next->val;
		temp = temp->next;
	}
	return (max);
}

void		rev_sort_stack(t_prop *xt)
{
	int max;
	
	while (xt->stack_b != 0)
	{
		max = get_max_2(xt->stack_b);
		if (xt->stack_b->val == max)
			push_top(&xt->stack_b, &xt->stack_a, op_b, xt);
		else
			rotate_stack(&xt->stack_b, op_b, xt);
	}
}