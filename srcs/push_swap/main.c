/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:31 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/22 14:04:54 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_prop(t_prop *xt)
{
	xt->stack_a = 0;
	xt->stack_b = 0;
}

void		print_stack(t_nbr *stack)
{
	t_nbr *temp;

	temp = stack;
	while (temp != 0)
	{
		printf("Number:%d	|	", temp->val);
		printf("pos:%d	|	", temp->pos);
		printf("type_a:%d	|	", temp->type_a);
		printf("type_b:%d	|	", temp->type_b);
		printf("to_top:%d	|	", temp->to_top);
		printf("to_fit:%d	|	", temp->to_fit);
		printf("PUSHME:%d\n", temp->pushme);
		temp = temp->next;
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	int		x;
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		ft_puterr(er_mem);
	init_prop(xt);
	x = 1;
	if (argc == 2)
	{
		check_str(argv[1]);
		xt->str = strdup(argv[1]);
	}
	else if (argc > 2)
	{
		xt->str = ft_strnew(1);
		while (x < argc)
		{
			arg_to_str(argv[x], xt);
			x++;
		}
		check_str(xt->str);
	}
	else
		ft_puterr(er_usg);
	process_input(xt);
	init_sorting(xt);
	return (0);
}
