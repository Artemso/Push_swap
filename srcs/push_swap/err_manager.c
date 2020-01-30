/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/30 16:17:17 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_puterr(int x)
{
	if (x == er_usg)
	{
		ft_putstr("Usage:\n");
		ft_putstr("./push_swap $(ARGS)\n");
		ft_putstr("push_swap takes list of arguments");
		ft_putstr(" or an argument string\n\n");
		exit(0);
	}
	else if (x == er_inp)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	else if (x == er_mem)
	{
		ft_putstr("Memory Error\n");
		exit(0);
	}
}
