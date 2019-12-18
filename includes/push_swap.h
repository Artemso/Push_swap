/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:00:02 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 14:17:50 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/*
** Linked List struct
*/

typedef struct	s_nbr
{
	int				val;
	struct t_nbr	*next;
}				t_nbr;

/*
** Push_Swap struct
*/

typedef struct	s_prop
{
	t_nbr	**st_a;
	t_nbr	**st_b;
	size_t	total;
	char	*str;
}				t_prop;

/*
** Error Management
*/

void			ft_puterr(int x);

/*
** Get Input
*/

int				check_str(char *input);
void			arg_to_str(char *input, t_prop *xt);

/*
** Process Input
*/

void			process_input(t_prop *xt);

#endif
