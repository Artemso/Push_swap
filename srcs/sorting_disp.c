/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_disp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:01:30 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 14:08:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_sorting(t_prop *xt)
{
	if (xt->total <= 6)
		sort_stack_small(xt);
	else
		sort_stack_med(xt);
}
