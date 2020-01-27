/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:18:47 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 14:14:39 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_minmax(int len, t_prop *xt, t_nbr *stack)
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

int		get_len(t_nbr *stack)
{
	int	ret;

	ret = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		ret++;
	}
	return (ret);
}

int		get_max(t_nbr *stack)
{
	int		max;

	max = stack->val;
	while (stack->next != 0)
	{
		if (stack->next->val > max)
			max = stack->next->val;
		stack = stack->next;
	}
	return (max);
}

int		get_min(t_nbr *stack)
{
	t_nbr	*temp;
	int		min;

	temp = stack;
	min = temp->val;
	while (temp->next != 0)
	{
		if (temp->next->val < min)
			min = temp->next->val;
		temp = temp->next;
	}
	return (min);
}

int		get_n_pos(int nb, t_nbr *stack)
{
	int	pos;

	pos = 0;
	while (stack != 0)
	{
		if (stack->val == nb)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}
