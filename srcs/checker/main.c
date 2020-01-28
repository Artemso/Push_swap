/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:22:59 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 14:34:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	init_prop(t_prop *xt)
{
	xt->stack_a = 0;
	xt->stack_b = 0;
	xt->cnt = 1;
	xt->i_flag = 0;
	xt->v_flag = 0;
	xt->t_flag = 0;
	xt->ops = 0;
	xt->pause = 1;
	xt->color = 16724530;
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
	int len;

	check_str(xt->str);
	process_input(xt);
	len = get_len(xt->stack_a);
	if (len < 451)
		visualise(xt);
	else
		ft_puterr(er_max);
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
			xt->ops += 1;
			free(line);
		}
	}
	check_stacks(xt);
}

static void	check_flag(int argc, char **argv, t_prop *xt)
{
	if (!argv[1])
		ft_puterr(er_usg);
	if (ft_strcmp(argv[1], "-v") == 0 && argc < 3)
		ft_puterr(er_inp);
	if (ft_strcmp(argv[1], "-v") == 0 && argv[2][0] == '-')
	{
		xt->color = ft_atoi(argv[2]);
		xt->color *= -1;
		xt->cnt += 2;
		xt->v_flag = 1;
	}
	else if (ft_strcmp(argv[1], "-v") == 0)
	{
		xt->v_flag = 1;
		xt->cnt += 1;
	}
	else if (ft_strcmp(argv[1], "-t") == 0)
	{
		xt->t_flag = 1;
		xt->cnt += 1;
	}
	else if (ft_strcmp(argv[1], "-i") == 0)
		xt->i_flag = 1;
}

void		start_run(t_prop *xt)
{
	if (xt->i_flag == 1)
		ft_puterr(er_info);
	else if (xt->t_flag == 1)
	{
		run_checker(xt);
		ft_putstr("Operations performed: ");
		ft_putstr(ft_itoa(xt->ops));
		ft_putstr("\n");
	}
	else if (xt->v_flag == 1)
		run_visual(xt);
	else
		run_checker(xt);
}

int			main(int argc, char **argv)
{
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		ft_puterr(er_mem);
	init_prop(xt);
	check_flag(argc, argv, xt);
	if (argc == 2 || argc == 3)
	{
		xt->str = strdup(argv[xt->cnt]);
	}
	else if (argc > 2)
	{
		xt->str = ft_strnew(1);
		while (xt->cnt < argc)
		{
			arg_to_str(argv[xt->cnt], xt);
			xt->cnt++;
		}
	}
	start_run(xt);
	return (0);
}
