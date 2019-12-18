/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:46 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 14:10:10 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_str(char *input)
{
	int	x;

	x = 0;
	while (input[x] != '\0')
	{
		if (!(input[x] == ' ' || ft_isdigit(input[x])))
			return (0);
		x++;
	}
	return (1);
}

void		arg_to_str(char *input, t_prop *xt)
{
	ft_safestrjoin(&xt->str, input, 0);
	ft_safestrjoin(&xt->str, " ", 0);
}
