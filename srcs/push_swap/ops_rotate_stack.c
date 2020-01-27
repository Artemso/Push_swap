/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:25:40 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:49:52 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void		rotate_stack(t_nbr **stack, int op)
{
	rotate(stack);
	if (op == op_a)
		ft_putstr("ra\n");
	else if (op == op_b)
		ft_putstr("rb\n");
}

void		rotate_stack_2(t_nbr **stack, t_nbr **stack2)
{
	rotate(stack);
	rotate(stack2);
	ft_putstr("rr\n");
}
