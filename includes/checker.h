/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:16:36 by solopov           #+#    #+#             */
/*   Updated: 2020/01/11 13:10:27 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>
# include "mlx.h"

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

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
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
void				push_top(t_nbr **stack, t_nbr **stack2, t_prop *xt);
void				rotate_stack(t_nbr **stack, t_prop *xt);
void				rotate_stack_two(t_nbr **stack, t_nbr **stack2, t_prop *xt);
void				rrotate_stack(t_nbr	**stack, t_prop *xt);
void				rrotate_stack_two(t_nbr	**stack, t_nbr	**stack2, t_prop *xt);
void				swap_top(t_nbr	**stack, t_prop *xt);
void				swap_top_two(t_nbr	**stack, t_nbr	**stack2, t_prop *xt);

/*
** Validation
*/

void				apply_instruction(char *line, t_prop *xt);
void				check_stacks(t_prop *xt);

/*
** Visuals
*/

void				visualise(t_prop *xt);
int					key_hook_press(int keycode, t_prop *xt);

#endif
