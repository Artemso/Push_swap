/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:09:32 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/21 17:46:35 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_closestval(int len, t_nbr *stack, t_prop *xt)
{
	int cnt;
	int avg;
	int prevmax;
	int prevmin;

	prevmin = xt->min;
	prevmax = xt->max;
	cnt = 0;
	avg = (xt->max + xt->min) / 2;
	//printf("avg:%d\n", avg);
	while (cnt < len)
	{
		if (stack->val < avg)
		{
			if (stack->val + avg > prevmin + avg)
				prevmin = stack->val;
		}
		else if (stack->val >= avg)
		{
			if (stack->val - avg < prevmax - avg)
				prevmax = stack->val;
		}
		stack = stack->next;
		cnt++;
	}
	if (prevmax - avg > avg - prevmin)
		xt->pivot = prevmin;
	else
		xt->pivot = prevmax;
}

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

int	get_min(t_nbr *stack)
{
	t_nbr	*temp;
	int		min;

	temp = stack;
	min = temp->val;
	while (temp->next != 0)
	{
		if (temp->next->val < min)
			min = temp->next->val;
		temp = temp->next;
	}
	return (min);
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

void	get_pivot_val(int len, t_prop *xt, t_nbr *stack)
{
	int		cnt;
	t_nbr	*temp;

	get_minmax(len, xt, stack);
	find_closestval(len, stack, xt);
}
