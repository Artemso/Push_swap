/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:33 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 17:04:45 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	check_swap(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_top(&ST_A);
	if (ft_strcmp(line, "sb") == 0)
		swap_top(&ST_B);
	if (ft_strcmp(line, "ss") == 0)
		swap_top_2(&ST_A, &ST_B);
}

static void	check_rotate(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_stack(&ST_A);
	if (ft_strcmp(line, "rb") == 0)
		rotate_stack(&ST_B);
	if (ft_strcmp(line, "rr") == 0)
		rotate_stack_2(&ST_A, &ST_B);
}

static void	check_rrotate(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "rra") == 0)
		rrotate_stack(&ST_A);
	if (ft_strcmp(line, "rrb") == 0)
		rrotate_stack(&ST_B);
	if (ft_strcmp(line, "rrr") == 0)
		rrotate_stack_2(&ST_A, &ST_B);
}

static void	check_push(char *line, t_prop *xt)
{
	if (ft_strcmp(line, "pb") == 0)
		push_top(&ST_A, &ST_B);
	if (ft_strcmp(line, "pa") == 0)
		push_top(&ST_B, &ST_A);
}

void	apply_instruction(char *line, t_prop *xt)
{
	check_swap(line, xt);
	check_rotate(line, xt);
	check_rrotate(line, xt);
	check_push(line, xt);
}
