/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:00:02 by asolopov          #+#    #+#             */
/*   Updated: 2019/12/18 17:29:53 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ST_A xt->stack_a
# define ST_B xt->stack_b

/*
** Enum for Error Handling
*/

typedef enum	e_errors
{
	er_mem = 0,
	er_usg,
	er_inp
}				t_errors;

/*
** Linked List struct
*/

typedef struct		s_nbr
{
	int				val;
	struct s_nbr	*next;
}					t_nbr;

/*
** Push_Swap struct
*/

typedef struct		s_prop
{
	t_nbr			*stack_a;
	t_nbr			*stack_b;
	size_t			total;
	char			*str;
}					t_prop;

/*
** Error Management
*/

void				ft_puterr(int x);

/*
** Get Input
*/

void				check_str(char *input);
void				arg_to_str(char *input, t_prop *xt);

/*
** Process Input
*/

void				process_input(t_prop *xt);

/*
** Stack Manipulation
*/

void				push_top(t_prop *xt, int code);
void				rotate_stack(t_prop *xt, int code);
void				rrotate_stack(t_prop *xt, int code);
void				swap_top(t_prop *xt, int code);

#endif
