/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_vals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 15:01:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		is_sorted(t_nbr *head)
{
	t_nbr *temp;

	temp = head;
	while (T_NXT != 0)
	{
		if (T_VAL > T_NXT->val)
			return (0);
		temp = T_NXT;
	}
	return (1);
}

void	sort_two(t_nbr **stack)
{
	if (is_sorted(*stack) != 1)
		swap_top(stack, op_a);
}

void	sort_three(t_nbr **stack)
{
	t_nbr	*temp;

	temp = *stack;
	while (is_sorted(temp) != 1)
	{
		if (T_VAL > T_NXT->val && T_NXT->val > T_NXT->next->val)
		{
			swap_top(&temp, op_a);
			rrotate_stack(&temp, op_a);
		}
		else if (T_VAL > T_NXT->val && T_VAL < T_NXT->next->val)
			swap_top(&temp, op_a);
		else if (T_VAL > T_NXT->val && T_NXT->val < T_NXT->next->val)
			rotate_stack(&temp, op_a);
		else if (T_VAL < T_NXT->val && T_VAL < T_NXT->next->val)
		{
			swap_top(&temp, op_a);
			rotate_stack(&temp, op_a);
		}
		else if (T_VAL < T_NXT->val && T_NXT->val > T_NXT->next->val)
			rrotate_stack(&temp, op_a);
	}
	*stack = temp;
}
