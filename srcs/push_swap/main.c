/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:31 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/29 17:52:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/push_swap.h"

static void	init_prop(t_prop *xt)
{
	xt->stack_a = 0;
	xt->stack_b = 0;
	if (!(xt->push_data = (t_push *)malloc(sizeof(t_push))))
		ft_puterr(er_mem);
}

void		free_mem(t_prop *xt)
{
	t_nbr *temp;

	while (xt->stack_a != 0)
	{
		temp = xt->stack_a->next;
		free(xt->stack_a);
		xt->stack_a = temp;
	}
	free(xt->push_data);
	free(xt);
}

int			main(int argc, char **argv)
{
	int		x;
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		ft_puterr(er_mem);
	init_prop(xt);
	x = 1;
	if (argc == 2)
		xt->str = strdup(argv[1]);
	else if (argc > 2)
	{
		xt->str = ft_strnew(1);
		while (x < argc)
		{
			arg_to_str(argv[x], xt);
			x++;
		}
	}
	else
		ft_puterr(er_usg);
	check_str(xt->str);
	process_input(xt);
	if (is_sorted(xt->stack_a) == 0)
		sort_stack_quick(xt);
	return (0);
}
