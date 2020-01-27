/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:46 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/27 10:41:48 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		check_str(char *input)
{
	int	x;

	x = 0;
	while (input[x] != '\0')
	{
		if (!(input[x] == ' ' || ft_isdigit(input[x]) || input[x] == '-'))
			ft_puterr(er_inp);
		x++;
	}
}

void		arg_to_str(char *input, t_prop *xt)
{
	ft_safestrjoin(&xt->str, input, 0);
	ft_safestrjoin(&xt->str, " ", 0);
}
