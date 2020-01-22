/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/22 12:31:16 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	count_moves_to_top(t_prop *xt)
{
	t_nbr	*head;
	int		len;

	head = xt->stack_b;
	len = get_len(xt->stack_b);
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

static int	locate_min_pos(t_nbr *stack)
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
	//printf("min pos:%d\n", pos);
	return (pos);
}

static int	locate_max_pos(t_nbr *stack)
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
	//printf("max pos:%d\n", pos);
	return (pos);
}

void	count_moves_to_fit(t_prop *xt)
{
	t_nbr	*head_a;
	t_nbr	*head_b;
	int		minpos;
	int		maxpos;
	int		len;

	len = get_len(xt->stack_a);
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
			if (xt->stack_b->val > xt->max)
			{
				rule_max(maxpos, len, xt);
				break ;
			}
			else if (xt->stack_b->val < xt->min)
			{
				rule_min(minpos, len, xt);
				break ;
			}
			else if (ST_B->val > ST_A->val && ST_B->val < ST_A->next->val)
			{
				rule_insertion(len, xt);
				break ;
			}
			else if (ST_B->val < ST_A->val && ST_B->val > last_val(ST_A))
			{
				xt->stack_b->to_fit = 0;
				xt->stack_b->type_a = rra;
				break ;
			}
			xt->stack_a = xt->stack_a->next;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_a = head_a;
	xt->stack_b = head_b;
}
