/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fit_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:16:39 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/23 21:58:53 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rule_max(int maxpos, int len, t_prop *xt)
{
	if (maxpos <= len / 2)
	{
		xt->stack_b->to_fit = maxpos + 1;
		xt->stack_b->type_a = ra;
	}
	else
	{
		xt->stack_b->to_fit = len - maxpos - 1;
		xt->stack_b->type_a = rra;
	}
	return (1);
}

int	rule_min(int minpos, int len, t_prop *xt)
{
	if (minpos <= len / 2)
	{
		xt->stack_b->to_fit = minpos;
		xt->stack_b->type_a = ra;
	}
	else
	{
		xt->stack_b->to_fit = len - minpos;
		xt->stack_b->type_a = rra;
	}
	return (1);
}

int	rule_insertion(int len, t_prop *xt)
{
	if (xt->stack_a->next->pos <= len / 2)
	{
		xt->stack_b->to_fit = xt->stack_a->next->pos;
		xt->stack_b->type_a = ra;
	}
	else
	{
		xt->stack_b->to_fit = len - xt->stack_a->next->pos;
		xt->stack_b->type_a = rra;
	}
	return (1);
}
