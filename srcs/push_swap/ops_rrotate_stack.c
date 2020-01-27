/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:26:44 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:41:11 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rrotate(t_nbr **stack)
{
	t_nbr	*slow;
	t_nbr	*fast;

	slow = 0;
	fast = *stack;
	while (fast->next != 0)
	{
		slow = fast;
		fast = fast->next;
	}
	slow->next = 0;
	fast->next = *stack;
	*stack = fast;
}

void		rrotate_stack(t_nbr **stack, int op)
{
	rrotate(stack);
	if (op == op_a)
		ft_putstr("rra\n");
	else if (op == op_b)
		ft_putstr("rrb\n");
}

void		rrotate_stack_2(t_nbr **stack, t_nbr **stack2)
{
	rrotate(stack);
	rrotate(stack2);
	ft_putstr("rrr\n");
}
