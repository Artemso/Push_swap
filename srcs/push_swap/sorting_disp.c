/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_disp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:01:30 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/08 11:00:22 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_sorting(t_prop *xt)
{
	if (xt->total <= 5)
		sort_stack_small(xt);
	else
		sort_stack_med(xt);
}
