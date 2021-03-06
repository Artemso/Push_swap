/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 14:07:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		count_moves_to_top(int len, t_prop *xt)
{
	t_nbr	*head;

	head = xt->stack_b;
	while (xt->stack_b != 0)
	{
		if (xt->stack_b->pos <= len / 2)
		{
			xt->stack_b->to_top = xt->stack_b->pos;
			xt->stack_b->type_b = rb;
		}
		else
		{
			xt->stack_b->to_top = len - xt->stack_b->pos;
			xt->stack_b->type_b = rrb;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_b = head;
}

static int	last_val(t_nbr *stack)
{
	int lastval;

	while (stack != 0)
	{
		lastval = stack->val;
		stack = stack->next;
	}
	return (lastval);
}

static int	select_move(int maxpos, int minpos, int len, t_prop *xt)
{
	int ret;

	ret = 0;
	if (xt->stack_b->val > xt->max)
		ret = rule_max(maxpos, len, xt);
	else if (xt->stack_b->val < xt->min)
		ret = rule_min(minpos, len, xt);
	else if (ST_B->val > ST_A->val && ST_B->val < ST_A->next->val)
		ret = rule_insertion(len, xt);
	else if (ST_B->val < ST_A->val && ST_B->val > last_val(ST_A))
	{
		xt->stack_b->to_fit = 0;
		xt->stack_b->type_a = rra;
		ret = 1;
	}
	return (ret);
}

void		count_moves_to_fit(int len, t_prop *xt)
{
	t_nbr	*head_a;
	t_nbr	*head_b;
	int		minpos;
	int		maxpos;

	head_a = xt->stack_a;
	head_b = xt->stack_b;
	get_minmax(len, xt, xt->stack_a);
	minpos = locate_min_pos(xt->stack_a);
	maxpos = locate_max_pos(xt->stack_a);
	while (xt->stack_b != 0)
	{
		xt->stack_a = head_a;
		while (xt->stack_a->next != 0)
		{
			if (select_move(maxpos, minpos, len, xt) == 1)
				break ;
			xt->stack_a = xt->stack_a->next;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_a = head_a;
	xt->stack_b = head_b;
}
