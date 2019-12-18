/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:07:48 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 14:52:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_stack(char **array, t_prop *xt)
{
	xt->total = 0;
	while (array[xt->total] != NULL)
		xt->total++;
	printf("total numbers:%d\n", xt->total);
}

void		process_input(t_prop *xt)
{
	char	**array;

	array = ft_strsplit(xt->str, ' ');
	fill_stack(array, xt);
}
