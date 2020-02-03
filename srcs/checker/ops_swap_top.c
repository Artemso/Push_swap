/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/03 14:25:38 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

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

void		swap_top(t_nbr **stack)
{
	if ((*stack) && (*stack)->next)
		swap_nodes(stack);
}

void		swap_top_2(t_nbr **stack, t_nbr **stack2)
{
	if ((*stack) && (*stack)->next)
	{
		if ((*stack2) && (*stack2)->next)
		{
			swap_nodes(stack);
			swap_nodes(stack2);
		}
	}
}
