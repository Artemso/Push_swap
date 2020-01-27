/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:26:44 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/23 15:05:42 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	rrotate(t_nbr **stack)
{
	t_nbr	*slow;
	t_nbr	*fast;

	slow = 0;
	fast = *stack;
	while (fast->next != 0)
	{
		slow = fast;
		fast = fast->next;
	}
	slow->next = 0;
	fast->next = *stack;
	*stack = fast;
}

void		rrotate_stack(t_nbr **stack, t_prop *xt)
{
	rrotate(stack);
	xt->steps_taken += 1;
}

void		rrotate_stack_2(t_nbr **stack, t_nbr **stack2, t_prop *xt)
{
	rrotate(stack);
	rrotate(stack2);
	xt->steps_taken += 1;
}
