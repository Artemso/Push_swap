/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:25:40 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 17:17:02 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	rotate(t_nbr **head)
{
	t_nbr	*curr;
	t_nbr	*rotme;

	rotme = *head;
	curr = *head;
	*head = curr->next;
	while (curr->next != 0)
		curr = curr->next;
	rotme->next = 0;
	curr->next = rotme;
}

void		rotate_stack(t_nbr **stack)
{
	if ((*stack) && (*stack)->next)
		rotate(stack);
}

void		rotate_stack_2(t_nbr **stack, t_nbr **stack2)
{
	if ((*stack)->next && (*stack2)->next && (*stack) && (stack2))
	{
		rotate(stack);
		rotate(stack2);
	}
}
