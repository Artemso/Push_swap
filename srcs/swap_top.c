/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:26:22 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_nodes(t_nbr **stack);

void	swap_top(t_prop *xt, int code)
{
	if (code == 0)
		swap_nodes(xt->stack_a);
	else if (code == 1)
		swap_nodes(xt->stack_b);
	else if (code == 2)
	{
		swap_nodes(xt->stack_a);
		swap_nodes(xt->stack_b);
	}
}
