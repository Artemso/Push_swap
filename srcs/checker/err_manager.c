/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:18:36 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/28 12:19:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ft_puterr(int x)
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
		ft_putstr("Ti ugaraesh\n");
	exit(0);
}
