/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:56:31 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 14:14:09 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_prop(t_prop *xt)
{
	xt->str = ft_strnew(1);
}

int		main(int argc, char **argv)
{
	int		x;
	t_prop	*xt;

	if (!(xt = (t_prop *)malloc(sizeof(t_prop))))
		return (0);
	x = 1;
	if (argc == 2)
	{
		if (check_str(argv[1]) == 0)
			ft_puterr(1);
		xt->str = strdup(argv[1]);
	}
	else if (argc > 2)
	{
		xt->str = ft_strnew(1);
		while (x < argc)
		{
			arg_to_str(argv[x], xt);
			x++;
		}
		if (check_str(xt->str) == 0)
			ft_puterr(1);
	}
	else
		ft_puterr(0);
	process_input(xt);
	return (0);
}
