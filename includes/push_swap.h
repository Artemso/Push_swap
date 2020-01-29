/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:00:02 by asolopov          #+#    #+#             */
/*   Updated: 2020/01/29 18:20:32 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ST_A	xt->stack_a
# define ST_B	xt->stack_b
# define T_NXT	temp->next
# define T_VAL	temp->val

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

typedef enum	e_moves
{
	rb = 0,
	rrb,
	ra,
	rra
}				t_moves;

/*
** Linked List struct
*/

typedef struct		s_nbr
{
	long long		val;
	int				to_top;
	int				to_fit;
	int				pos;
	int				moves;
	int				pushme;
	int				type_a;
	int				type_b;
	struct s_nbr	*next;
}					t_nbr;

/*
** Push_Swap struct
*/

typedef struct		s_push
{
	int				to_top;
	int				to_fit;
	int				type_a;
	int				type_b;
	int				moves;
	int				pushed;
}					t_push;

typedef struct		s_prop
{
	t_nbr			*stack_a;
	t_nbr			*stack_b;
	int				total;
	int				min;
	int				max;

	int				pivot;
	int				store;
	t_push			*push_data;

	char			*str;
}					t_prop;

/*
** Process Input, Errors and Memory
*/

t_nbr				*new_node(long long content);
void				check_str(char *input);
void				check_stack(t_prop *xt);
void				arg_to_str(char *input, t_prop *xt);
void				process_input(t_prop *xt);
void				check_duplicates(t_prop *xt);
void				ft_puterr(int x);
void				free_mem(t_prop *xt);
void				check_array(char **array);
void				check_symbols(char **array, int cnt, int cnt2);

/*
** Stack Operations
*/

void				push_top(t_nbr **stack, t_nbr **stack2, int op);
void				rotate_stack(t_nbr **stack, int op);
void				rotate_stack_2(t_nbr **stack, t_nbr **stack2);
void				rrotate_stack(t_nbr **stack, int op);
void				rrotate_stack_2(t_nbr **stack, t_nbr **stack2);
void				swap_top(t_nbr **stack, int op);
void				swap_top_2(t_nbr **stack, t_nbr **stack2);

/*
** Get Stack Information
*/

int					get_min(t_nbr *stack);
void				get_minmax(int len, t_prop *xt, t_nbr *stack);
int					get_max(t_nbr *stack);
int					get_len(t_nbr *stack);
int					get_n_pos(int nb, t_nbr *stack);

void				save_push_data(t_prop *xt);
void				compare_moves(t_prop *xt);
void				combine_moves(t_prop *xt);
void				set_positions(t_prop *xt);
void				select_to_push(t_prop *xt);

/*
** Stack Sorting
*/

void				push_val(t_prop *xt);
void				split_stack(int len, t_prop *xt);

void				sort_two(t_nbr **stack);
void				sort_three(t_nbr **stack);
void				sort_stack_quick(t_prop *xt);
void				init_sorting(t_prop *xt);
int					is_sorted(t_nbr *head);

void				routine_b_nosplit(t_prop *xt);
void				routine_b_split(t_prop *xt);
void				routine_a(t_prop *xt);

void				rotate_ra_rb_totop(t_prop *xt);
void				rotate_ra_rb_tofit(t_prop *xt);
void				rotate_rra_rrb_totop(t_prop *xt);
void				rotate_rra_rrb_tofit(t_prop *xt);
void				do_rotate(int cnt, int pos, t_prop *xt);
void				do_rrotate(int cnt, int len, int pos, t_prop *xt);

/*
** Extra
*/

void				count_moves_to_fit(int len, t_prop *xt);
void				count_moves_to_top(int len, t_prop *xt);
void				get_pivot_val(int len, t_prop *xt, t_nbr *stack);

void				ra_rb(t_prop *xt);
void				ra_rrb(t_prop *xt);
void				rra_rb(t_prop *xt);
void				rra_rrb(t_prop *xt);

int					rule_insertion(int len, t_prop *xt);
int					rule_min(int minpos, int len, t_prop *xt);
int					rule_max(int maxpos, int len, t_prop *xt);

int					locate_max_pos(t_nbr *stack);
int					locate_min_pos(t_nbr *stack);

#endif
