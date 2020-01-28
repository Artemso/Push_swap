/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:40:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 13:58:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		is_sorted(t_nbr *head)
{
	t_nbr *temp;

	temp = head;
	while (temp->next != 0)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	check_stacks(t_prop *xt)
{
	if (is_sorted(xt->stack_a) && xt->stack_b == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
