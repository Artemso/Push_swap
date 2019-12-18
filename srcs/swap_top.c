/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 18:16:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_nbr	*swap_nodes(t_nbr *head)
{
	t_nbr *temp;
}

void	swap_top(t_prop *xt, int code)
{
	if (code == 0)
		xt->stack_a = swap_nodes(xt->stack_a);
	else if (code == 1)
		swap_nodes(xt->stack_b);
	else if (code == 2)
	{
		swap_nodes(xt->stack_a);
		swap_nodes(xt->stack_b);
	}
}
