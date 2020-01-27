/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:58:28 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 14:01:42 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_positions(t_prop *xt)
{
	t_nbr	*head_b;
	t_nbr	*head_a;
	int		cnt;

	cnt = 0;
	head_b = ST_B;
	while (ST_B != 0)
	{
		ST_B->pos = cnt;
		cnt += 1;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
	cnt = 0;
	head_a = ST_A;
	while (ST_A != 0)
	{
		ST_A->pos = cnt;
		cnt += 1;
		ST_A = ST_A->next;
	}
	ST_A = head_a;
}

void	combine_moves(t_prop *xt)
{
	t_nbr	*head_b;

	head_b = ST_B;
	while (ST_B != 0)
	{
		if ((ST_B->type_a == ra && ST_B->type_b == rb) || \
			(ST_B->type_a == rra && ST_B->type_b == rrb))
		{
			if (ST_B->to_top > ST_B->to_fit)
				ST_B->moves = ST_B->to_top;
			else
				ST_B->moves = ST_B->to_fit;
		}
		else if (ST_B->type_a == ra && ST_B->type_b == rrb)
			ST_B->moves = ST_B->to_top + ST_B->to_fit;
		else if (ST_B->type_a == rra && ST_B->type_b == rb)
			ST_B->moves = ST_B->to_top + ST_B->to_fit;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

void	compare_moves(t_prop *xt)
{
	t_nbr	*head_b;
	int		movmin;
	int		posmin;

	movmin = ST_B->moves;
	posmin = 0;
	head_b = ST_B;
	while (ST_B->next != 0)
	{
		if (ST_B->next->moves < movmin)
		{
			movmin = ST_B->next->moves;
			posmin = ST_B->next->pos;
		}
		ST_B = ST_B->next;
	}
	ST_B = head_b;
	while (ST_B != 0)
	{
		if (posmin == ST_B->pos)
			ST_B->pushme = 1;
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

void	save_push_data(t_prop *xt)
{
	t_nbr	*head_b;

	head_b = ST_B;
	while (ST_B != 0)
	{
		if (ST_B->pushme == 1)
		{
			xt->push_data->to_fit = ST_B->to_fit;
			xt->push_data->to_top = ST_B->to_top;
			xt->push_data->type_a = ST_B->type_a;
			xt->push_data->type_b = ST_B->type_b;
		}
		ST_B = ST_B->next;
	}
	ST_B = head_b;
}

void	push_val(t_prop *xt)
{
	if (xt->push_data->type_a == ra && xt->push_data->type_b == rb)
		ra_rb(xt);
	else if (xt->push_data->type_a == ra && xt->push_data->type_b == rrb)
		ra_rrb(xt);
	else if (xt->push_data->type_a == rra && xt->push_data->type_b == rb)
		rra_rb(xt);
	else if (xt->push_data->type_a == rra && xt->push_data->type_b == rrb)
		rra_rrb(xt);
}
