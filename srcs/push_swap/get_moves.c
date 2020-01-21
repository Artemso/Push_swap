/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:42:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/21 18:08:40 by asolopov         ###   ########.fr       */
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

void	count_moves_to_fit(t_prop *xt)
{
	t_nbr	*head_a;
	t_nbr	*head_b;
	int		minpos;

	head_a = xt->stack_a;
	head_b = xt->stack_b;
	get_minmax(get_len(xt->stack_a), xt, xt->stack_a);
	minpos = locate_min_pos(xt->stack_a);
	while (xt->stack_b != 0)
	{
		xt->stack_a = head_a;
		while (xt->stack_a->next != 0)
		{
			if (xt->stack_b->val < xt->min)
			{
				//printf("Used rule 1 for %d\n", xt->stack_b->val);
				xt->stack_b->to_fit = minpos;
				xt->stack_b->type_a = ra;
				break ;
			}
			else if (xt->stack_b->val > xt->stack_a->val && xt->stack_b->val < xt->stack_a->next->val)
			{
				//printf("Used rule 2 for %d\n", xt->stack_b->val);
				xt->stack_b->to_fit = xt->stack_a->next->pos;
				xt->stack_b->type_a = ra;
				break ;
			}
			else if (ST_B->val < ST_A->val && ST_B->val > last_val(ST_A))
			{
				//printf("Used rule 3 for %d\n", xt->stack_b->val);
				xt->stack_b->to_fit = 0;
				xt->stack_b->type_a = ra;
				break ;
			}
			xt->stack_a = xt->stack_a->next;
		}
		xt->stack_b = xt->stack_b->next;
	}
	xt->stack_a = head_a;
	xt->stack_b = head_b;
}
