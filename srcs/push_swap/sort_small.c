/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:26:54 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/23 21:34:20 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		get_minmax(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;
	t_nbr	*temp;

	cnt = 0;
	temp = stack;
	xt->min = T_VAL;
	xt->max = T_VAL;
	while (cnt < len - 1)
	{
		if (T_NXT->val < xt->min)
			xt->min = T_NXT->val;
		if (T_NXT->val > xt->max)
			xt->max = T_NXT->val;
		temp = T_NXT;
		cnt += 1;
	}
}

int	is_sorted(t_nbr *head)
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

void	sort_three(t_nbr **stack, t_prop *xt)
{
	t_nbr	*temp;

	temp = *stack;
	while (is_sorted(temp) != 1)
	{
		if (T_VAL > T_NXT->val && T_NXT->val > T_NXT->next->val)
		{
			swap_top(&temp, op_a, xt);
			rrotate_stack(&temp, op_a, xt);
		}
		else if (T_VAL > T_NXT->val && T_VAL < T_NXT->next->val)
			swap_top(&temp, op_a, xt);
		else if (T_VAL > T_NXT->val && T_NXT->val < T_NXT->next->val)
			rotate_stack(&temp, op_a, xt);
		else if (T_VAL < T_NXT->val && T_VAL < T_NXT->next->val)
		{
			swap_top(&temp, op_a, xt);
			rotate_stack(&temp, op_a, xt);
		}
		else if (T_VAL < T_NXT->val && T_NXT->val > T_NXT->next->val)
			rrotate_stack(&temp, op_a, xt);
	}
	*stack = temp;
}
