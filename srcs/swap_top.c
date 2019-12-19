/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/19 17:59:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void		swap_top(t_prop *xt, int code)
{
	if (code == op_a)
		swap_nodes(&xt->stack_a);
	else if (code == op_b)
		swap_nodes(&xt->stack_b);
	else if (code == op_ab)
	{
		swap_nodes(&xt->stack_a);
		swap_nodes(&xt->stack_b);
	}
}
