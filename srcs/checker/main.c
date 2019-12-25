/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:24:13 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/25 17:05:30 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	check_stacks(t_prop *xt)
{
	ft_putstr("checked!\n");
}

static void	init_prop(t_prop *xt)
{
	xt->stack_a = 0;
	xt->stack_b = 0;
	xt->steps_taken = 0;
}

static void	apply_instruction(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_top(&xt->stack_a, op_a, xt);
	else if (ft_strcmp(line, "sb") == 0)
		swap_top(&xt->stack_b, op_b, xt);
}

int			main(int argc, char **argv)
{
	t_prop	*xt;
	char	*line;
	int		x;
	int		y;

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
	process_input(xt);
	while (y != 0)
	{
		y = get_next_line(0, &line);
		if (y != 0)
		{
			apply_instruction(line, xt);
			//free(line);
		}
	}
	check_stacks(xt);
}
