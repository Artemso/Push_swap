/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:22:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/20 11:05:38 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	push_top(t_nbr	**stack, t_nbr	**stack2)
{
	push_node(stack, stack2);
}
