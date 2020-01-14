/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:09:32 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/14 17:36:26 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_len(t_nbr *stack)
{
	int	ret;

	ret = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		ret++;
	}
	return (ret);
}

int	get_max(t_nbr *stack)
{
	t_nbr	*temp;
	int		max;

	temp = stack;
	max = temp->val;
	while (temp->next != 0)
	{
		if (temp->next->val > max)
			max = temp->next->val;
		temp = temp->next;
	}
	return (max);
}

t_elem	*new_elem(int content)
{
	t_elem	*node;

	if (!(node = (t_elem *)malloc(sizeof(t_elem))))
		ft_puterr(er_mem);
	node->val = content;
	node->next = NULL;
	return (node);
}
