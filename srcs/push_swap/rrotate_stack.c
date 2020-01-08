/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:26:44 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/08 11:07:18 by solopov          ###   ########.fr       */
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

void		rrotate_stack(t_nbr **stack, int op, t_prop *xt)
{
	rrotate(stack);
	if (op == op_a)
		ft_putstr("rra\n");
	else if (op == op_b)
		ft_putstr("rrb\n");
}

void		rrotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt)
{
	rrotate(stack);
	rrotate(stack2);
	ft_putstr("rrr\n");
}
