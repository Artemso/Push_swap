/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:25:40 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:26:18 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_nbr **stack);

void	rotate_stack(t_prop *xt, int code)
{
	if (code == 0)
		rotate(xt->stack_a);
	else if (code == 1)
		rotate(xt->stack_b);
	else if (code == 2)
	{
		rotate(xt->stack_a);
		rotate(xt->stack_b);
	}
}
