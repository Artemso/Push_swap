/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 17:18:34 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_nodes(t_nbr **head)
{
	t_nbr	*second;
	t_nbr	*temp;

	temp = *head;
	second = temp->next;
	temp->next = second->next;
	second->next = temp;
	*head = second;
}

void		swap_top(t_nbr **stack, int op)
{
	if ((*stack) && (*stack)->next)
	{
		swap_nodes(stack);
		if (op == op_a)
			ft_putstr("sa\n");
		else if (op == op_b)
			ft_putstr("sb\n");
	}
}

void		swap_top_2(t_nbr **stack, t_nbr **stack2)
{
	if ((*stack)->next && (*stack2)->next && (*stack) && (stack2))
	{
		swap_nodes(stack);
		swap_nodes(stack2);
		ft_putstr("ss\n");
	}
}
