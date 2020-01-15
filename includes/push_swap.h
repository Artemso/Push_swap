/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solopov <solopov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:00:02 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/15 17:47:08 by solopov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

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

typedef struct		s_elem
{
	int				val;
	struct s_elem	*next;
}					t_elem;

/*
** Push_Swap struct
*/

typedef struct		s_prop
{
	t_nbr			*stack_a;
	t_nbr			*stack_b;
	int				total;
	int				min;
	int				max;

	int				pivot;
	t_elem			*elems;

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

t_nbr				*new_node(int content);
void				push_top(t_nbr **stack, t_nbr **stack2, int op, t_prop *xt);
void				rotate_stack(t_nbr **stack, int op, t_prop *xt);
void				rotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt);
void				rrotate_stack(t_nbr **stack, int op, t_prop *xt);
void				rrotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt);
void				swap_top(t_nbr **stack, int op, t_prop *xt);
void				swap_top_two(t_nbr **stack, t_nbr **stack2, t_prop *xt);

/*
** Stack Sorting
*/

void				sort_three(t_nbr **stack, t_prop *xt);
void				sort_stack_small(t_prop *xt);
void				sort_stack_med(t_prop *xt);
void				sort_stack_quick(t_prop *xt);
void				init_sorting(t_prop *xt);
int					is_sorted(t_nbr *head);

/*
** Extra
*/

void				get_minmax(t_prop *xt, t_nbr *stack);
void				print_stack(t_nbr *stack);
void				print_elems(t_elem *stack);
int					get_len(t_nbr *stack);
t_elem				*new_elem(int content);

#endif
