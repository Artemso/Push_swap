/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:17:54 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/20 09:30:59 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_nodes(t_nbr **head)
{
	t_nbr	*second;
	t_nbr	*temp;

	temp = *head;
	second = temp->next;
	temp->next = second->next;
	second->next = temp;
	*head = second;
}

void		swap_top(t_nbr	**stack)
{
	swap_nodes(stack);
}

void		swap_top_two(t_nbr	**stack, t_nbr	**stack2)
{
	swap_nodes(stack);
	swap_nodes(stack2);
}
