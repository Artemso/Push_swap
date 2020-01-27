/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:22:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 18:28:42 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	init_prop(t_prop *xt)
{
	xt->stack_a = 0;
	xt->stack_b = 0;
}

int			check_flag(int argc, char **argv)
{
	if (argc < 2)
		ft_puterr(er_inp);
	if (ft_strcmp(argv[1], "-v") == 0 && argc < 3)
		ft_puterr(er_inp);
	if (ft_strcmp(argv[1], "-v") == 0)
		return (2);
	else
		return (1);
}

void		print_stack(t_nbr *stack)
{
	t_nbr *temp;
	
	temp = stack;
	while (temp != 0)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

static void	run_visual(t_prop *xt)
{
	check_str(xt->str);
	process_input(xt);
	visualise(xt);
}

static void	run_checker(t_prop *xt)
{
	char	*line;
	int		ret;

	check_str(xt->str);
	process_input(xt);
	ret = 1;
	while (ret != 0)
	{
		if ((ret = get_next_line(0, &line)) > 0)
		{
			apply_instruction(line, xt);
			free(line);
		}
	}
	check_stacks(xt);
}

int			main(int argc, char **argv)
{
	t_prop	*xt;
	int		x;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		ft_puterr(er_mem);
	init_prop(xt);
	x = check_flag(argc, argv);
	if (argc == 2 || argc == 3)
	{
		xt->str = strdup(argv[x]);
	}
	else if (argc > 2)
	{
		xt->str = ft_strnew(1);
		while (x < argc)
		{
			arg_to_str(argv[x], xt);
			x++;
		}
	}
	if (x == 2)
		run_visual(xt);
	else
		run_checker(xt);
}
