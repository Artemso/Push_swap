/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 14:17:17 by asolopov         ###   ########.fr       */
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
	ft_putstr("RRR:	rra and rrb at the same time\n");
}

void		ft_puterr(int x)
{
	if (x == er_usg)
		ft_putstr("Usage:\n./checker \"Argument String\"/ Argument List\n");
	else if (x == er_inp)
		ft_putstr("Input is incorrect.\n");
	else if (x == er_mem)
		ft_putstr("Memory Error.\n");
	else if (x == er_max)
		ft_putstr("Too many arguments to visualise.\n");
	else if (x == er_info)
		write_info();
	exit(0);
}
