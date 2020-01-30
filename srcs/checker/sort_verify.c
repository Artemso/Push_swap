/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:40:35 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/30 15:43:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	check_symbols(char **array, int cnt, int cnt2)
{
	while (array[cnt][cnt2] != '\0')
	{
		if (!(ft_isdigit(array[cnt][cnt2]) || array[cnt][cnt2] == '\0'))
			ft_puterr(er_inp);
		cnt2++;
	}
}

void	check_array(char **array)
{
	int cnt;
	int cnt2;

	cnt = 0;
	cnt2 = 0;
	if (!array[0])
		ft_puterr(er_inp);
	while (array[cnt])
	{
		cnt2 = 0;
		if (ft_isdigit(array[cnt][cnt2]))
			check_symbols(array, cnt, cnt2);
		else if (array[cnt][cnt2] == '-')
		{
			cnt2 = 1;
			check_symbols(array, cnt, cnt2);
		}
		else if (array[cnt][cnt2] == '+')
		{
			cnt2 = 1;
			check_symbols(array, cnt, cnt2);
		}
		cnt++;
	}
}

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
