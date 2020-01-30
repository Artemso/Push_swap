/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/30 16:17:40 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	write_info(void)
{
	ft_putstr("Push_Swap Project by asolopov\n\n");
	ft_putstr("Given a list of numbers (positive and negative, no duplicates)");
	ft_putstr(" sort it in the ascending order using Stack A and Stack B.\n");
	ft_putstr("The allowed operations are:\n\n");
	ft_putstr("SA:	swap a - swap first 2 elements at the top of stack a\n");
	ft_putstr("SB:	swap b - swap first 2 elements at the top of stack b\n");
	ft_putstr("SS:	sa and sb at the same time.\n");
	ft_putstr("PA:	push a - take the first element ");
	ft_putstr("at the top of b and put it at the top of a\n");
	ft_putstr("PB:	push b - take the first element ");
	ft_putstr("at the top of a and put it at the top of b\n");
	ft_putstr("RA:	rotate a - shift up all elements of stack a by 1\n");
	ft_putstr("RB:	rotate b - shift up all elements of stack b by 1\n");
	ft_putstr("RR:	ra and rb at the same time\n");
	ft_putstr("RRA:	rotate a - shift down all elements of stack a by 1\n");
	ft_putstr("RRB:	rotate b - shift down all elements of stack b by 1\n");
	ft_putstr("RRR:	rra and rrb at the same time\n\n");
}

static void	write_flags(void)
{
	ft_putstr("The checker program supports following flags:\n");
	ft_putstr("-v:		visualise, graphic representation using MLX library.");
	ft_putstr(" 450 numbers and less are allowed to visualise. Controls:\n");
	ft_putstr("		SPACE: play/pause\n");
	ft_putstr("		RIGHT ARROW: when paused, do 1 operation\n");
	ft_putstr("		ESC: quit\n\n");
	ft_putstr("-c (INT):	used optionally after -v flag ");
	ft_putstr("to modify stack display color\n\n");
	ft_putstr("-t:		total count, performs checking and displays ");
	ft_putstr("number of operations performed to sort the stack\n\n");
	ft_putstr("-i:		display information about the project.\n");
}

void		ft_puterr(int x)
{
	if (x == er_usg)
	{
		ft_putstr("Usage:\n");
		ft_putstr("./checker $(ARGS)\n");
		ft_putstr("./push_swap $(ARGS) | ./checker $(ARGS)\n");
		ft_putstr("checker takes list of arguments or an argument string\n\n");
		write_flags();
	}
	else if (x == er_inp)
		ft_putstr("Error\n");
	else if (x == er_mem)
		ft_putstr("Memory Error.\n");
	else if (x == er_max)
		ft_putstr("Too many arguments to visualise.\n");
	else if (x == er_info)
	{
		write_info();
		write_flags();
	}
	exit(0);
}
