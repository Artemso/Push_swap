/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:03:10 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 14:36:52 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_stack_med(t_prop *xt)
{
	t_nbr	*temp_a;
	t_nbr	*temp_b;
	int		x;

	temp_a = xt->stack_a;
	temp_b = xt->stack_b;
	get_minmax(xt, temp_a);
	x = get_len(temp_a);
	while (1)
	{
		x = get_len(temp_a);
		get_minmax(xt, temp_a);
		if (temp_a->val == xt->min || x == 1)
		{
			push_top(&temp_a, &temp_b, xt);
		}
		else
			rotate_stack(&temp_a, xt);
		if (x == 1)
			break ;
	}
	while (1)
	{
		x = get_len(temp_b);
		push_top(&temp_b, &temp_a, xt);
		if (x == 1)
			break ;
	}
	xt->stack_a = temp_a;
}
