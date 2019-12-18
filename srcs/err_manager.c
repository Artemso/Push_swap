/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 13:38:44 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_puterr(int x)
{
	if (x == 0)
	{
		ft_putstr("Usage: sosi zalupu\n");
		exit(0);
	}
	else if (x == 1)
	{
		ft_putstr("Input is incorrect\n");
		exit(0);
	}
	else if (x == 2)
	{
		ft_putstr("Broken input!\n");
		exit(0);
	}
	else if (x == 3)
	{
		ft_putstr("Conversions don't match parameters!\n");
		exit(0);
	}
}
