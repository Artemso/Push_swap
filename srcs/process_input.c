/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:07:48 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:13:54 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_nbr	*new_node(int content)
{
	t_nbr	*node;

	if (!(node = (t_nbr *)malloc(sizeof(t_nbr))))
		ft_puterr(er_mem);
	node->val = content;
	node->next = NULL;
	return (node);
}

static t_nbr	*fill_stack(char **array, t_prop *xt)
{
	t_nbr	*head;
	t_nbr	*curr;
	int		cnt;

	cnt = 0;
	curr = new_node(ft_atoi(array[cnt]));
	head = curr;
	while (++cnt < xt->total)
	{
		curr->next = new_node(ft_atoi(array[cnt]));
		curr = curr->next;
	}
	return (head);
}

static void	make_stack(char **array, t_prop *xt)
{
	xt->total = 0;
	while (array[xt->total] != NULL)
		xt->total++;
	printf("total numbers:%d\n", xt->total);
	xt->stack_a = fill_stack(array, xt);
}

void		process_input(t_prop *xt)
{
	char	**array;

	array = ft_strsplit(xt->str, ' ');
	ft_strdel(&xt->str);
	make_stack(array, xt);
}
