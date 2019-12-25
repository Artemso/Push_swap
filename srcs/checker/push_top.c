/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:22:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 17:32:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	push_node(t_nbr **stack_1, t_nbr **stack_2)
{
	t_nbr	*temp;

	temp = *stack_1;
	*stack_1 = (*stack_1)->next;
	if ((*stack_2) == 0)
	{
		*stack_2 = temp;
		(*stack_2)->next = 0;
	}
	else
	{
		temp->next = *stack_2;
		*stack_2 = temp;
	}
}

void	push_top(t_nbr **stack, t_nbr **stack2, t_prop *xt)
{
	push_node(stack, stack2);
	xt->steps_taken += 1;
}
