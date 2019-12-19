/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:25:40 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/19 17:29:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	rotate_stack(t_prop *xt, int code)
{
	if (code == 0)
		rotate(&xt->stack_a);
	else if (code == 1)
		rotate(&xt->stack_b);
	else if (code == 2)
	{
		rotate(&xt->stack_a);
		rotate(&xt->stack_b);
	}
}
