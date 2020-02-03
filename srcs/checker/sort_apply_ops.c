/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_apply_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/02/03 14:39:03 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int	check_swap(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "sa") == 0)
	{
		swap_top(&ST_A);
		return (1);
	}
	if (ft_strcmp(line, "sb") == 0)
	{
		swap_top(&ST_B);
		return (1);
	}
	if (ft_strcmp(line, "ss") == 0)
	{
		swap_top_2(&ST_A, &ST_B);
		return (1);
	}
	return (0);
}

static int	check_rotate(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "ra") == 0)
	{
		rotate_stack(&ST_A);
		return (1);
	}
	if (ft_strcmp(line, "rb") == 0)
	{
		rotate_stack(&ST_B);
		return (1);
	}
	if (ft_strcmp(line, "rr") == 0)
	{
		rotate_stack_2(&ST_A, &ST_B);
		return (1);
	}
	return (0);
}

static int	check_rrotate(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "rra") == 0)
	{
		rrotate_stack(&ST_A);
		return (1);
	}
	if (ft_strcmp(line, "rrb") == 0)
	{
		rrotate_stack(&ST_B);
		return (1);
	}
	if (ft_strcmp(line, "rrr") == 0)
	{
		rrotate_stack_2(&ST_A, &ST_B);
		return (1);
	}
	return (0);
}

static int	check_push(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "pb") == 0)
	{
		push_top(&ST_A, &ST_B);
		return (1);
	}
	if (ft_strcmp(line, "pa") == 0)
	{
		push_top(&ST_B, &ST_A);
		return (1);
	}
	return (0);
}

void		apply_instruction(char *line, t_prop *xt)
{
	int x;

	x = 0;
	x += check_swap(line, xt);
	x += check_rotate(line, xt);
	x += check_rrotate(line, xt);
	x += check_push(line, xt);
	if (x == 0)
		ft_puterr(er_inp);
}
