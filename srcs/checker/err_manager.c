/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 15:20:47 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_puterr(int x)
{
	if (x == er_usg)
	{
		ft_putstr("Usage:\n./checker \"Argument String\"/ Argument List\n");
		exit(0);
	}
	else if (x == er_inp)
	{
		ft_putstr("Input is incorrect.\n");
		exit(0);
	}
	else if (x == er_mem)
	{
		ft_putstr("Memory Error.\n");
		exit(0);
	}
}
