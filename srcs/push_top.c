/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:22:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:25:01 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_node(t_prop *xt);

void	push_top(t_prop *xt, int code)
{
	if (code == 0)
		push_node(xt);
	else if (code == 1)
		push_node(xt);
}
