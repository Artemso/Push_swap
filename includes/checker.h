/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:16:36 by solopov           #+#    #+#             */
/*   Updated: 2019/12/25 16:28:12 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

/*
** Enum for Operations, op_a move to b, op_b move to a
*/

typedef enum	e_opers
{
	op_a = 0,
	op_b,
	op_ab
}				t_opers;


/*
** Linked List struct
*/

typedef struct		s_nbr
{
	int				val;
	struct s_nbr	*next;
}					t_nbr;

/*
** Data container struct
*/

typedef struct		s_prop
{
	t_nbr			*stack_a;
	t_nbr			*stack_b;
	int				total;
	int				min;
	int				max;
	char			*str;
	int				steps_taken;
	int				run_cnt;
}					t_prop;

/*
** Stack Manipulation
*/

t_nbr				*new_node(int content);
void				push_top(t_nbr **stack, t_nbr **stack2, int op, t_prop *xt);
void				rotate_stack(t_nbr **stack, int op, t_prop *xt);
void				rotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt);
void				rrotate_stack(t_nbr	**stack, int op, t_prop *xt);
void				rrotate_stack_two(t_nbr	**stack, t_nbr	**stack2, t_prop *xt);
void				swap_top(t_nbr	**stack, int op, t_prop *xt);
void				swap_top_two(t_nbr	**stack, t_nbr	**stack2, t_prop *xt);

#endif
