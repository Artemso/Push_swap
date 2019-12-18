/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:26:44 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:27:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rrotate(t_nbr **stack);

void	rrotate_stack(t_prop *xt, int code)
{
	if (code == 0)
		rrotate(xt->stack_a);
	else if (code == 1)
		rrotate(xt->stack_b);
	else if (code == 2)
	{
		rrotate(xt->stack_a);
		rrotate(xt->stack_b);
	}
}
