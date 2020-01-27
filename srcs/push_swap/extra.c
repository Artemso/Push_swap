/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:55:30 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 13:56:48 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	do_rotate(int cnt, int pos, t_prop *xt)
{
	while (cnt < pos + 1)
	{
		rotate_stack(&ST_A, op_a);
		cnt++;
	}
}

void	do_rrotate(int cnt, int len, int pos, t_prop *xt)
{
	while (cnt < len - pos - 1)
	{
		rrotate_stack(&ST_A, op_a);
		cnt++;
	}
}

int		locate_min_pos(t_nbr *stack)
{
	int min;
	int pos;

	pos = 0;
	min = get_min(stack);
	while (stack->val != min)
	{
		pos += 1;
		stack = stack->next;
	}
	return (pos);
}

int		locate_max_pos(t_nbr *stack)
{
	int max;
	int pos;

	pos = 0;
	max = get_max(stack);
	while (stack->val != max)
	{
		pos += 1;
		stack = stack->next;
	}
	return (pos);
}
