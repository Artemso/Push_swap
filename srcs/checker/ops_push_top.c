/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:22:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 17:06:36 by asolopov         ###   ########.fr       */
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

void		push_top(t_nbr **stack, t_nbr **stack2)
{
	if ((*stack))
		push_node(stack, stack2);
}
