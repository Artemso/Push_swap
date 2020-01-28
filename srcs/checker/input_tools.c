/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:46 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 15:51:54 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	check_str(char *input)
{
	int	x;

	x = 0;
	while (input[x] != '\0')
	{
		if (!(input[x] == ' ' || ft_isdigit(input[x]) || input[x] == '-'))
			ft_puterr(er_inp);
		x++;
	}
}

void	check_duplicates(t_prop *xt)
{
	t_nbr	*copy;
	t_nbr	*temp;
	t_nbr	*head;

	temp = xt->stack_a;
	head = temp;
	while (temp != 0)
	{
		copy = temp;
		while (copy->next != 0)
		{
			if (temp->val == copy->next->val)
				ft_puterr(er_inp);
			copy = copy->next;
		}
		temp = temp->next;
	}
}

void	check_stack(t_prop *xt)
{
	t_nbr	*temp;

	temp = xt->stack_a;
	while (temp != 0)
	{
		if (temp->val > 2147483647 || temp->val < -2147483648)
			ft_puterr(er_inp);
		temp = temp->next;
	}
}

void	arg_to_str(char *input, t_prop *xt)
{
	ft_safestrjoin(&xt->str, input, 0);
	ft_safestrjoin(&xt->str, " ", 0);
}
