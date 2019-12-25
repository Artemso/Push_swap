/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:25:40 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 17:32:01 by asolopov         ###   ########.fr       */
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

void		rotate_stack(t_nbr **stack, t_prop *xt)
{
	rotate(stack);
	xt->steps_taken += 1;
}

void		rotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt)
{
	rotate(stack);
	rotate(stack2);
	xt->steps_taken += 1;
}

