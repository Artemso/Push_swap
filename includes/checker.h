/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 10:16:36 by solopov           #+#    #+#             */
/*   Updated: 2020/02/03 14:34:08 by asolopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdio.h>
# include "mlx.h"

# define ST_A		xt->stack_a
# define ST_B		xt->stack_b
# define XT_IMG		xt->img_ptr
# define XT_MLX		xt->mlx_ptr
# define XT_IDATA	xt->img_data
# define XT_WIN		xt->win_ptr
# define WID		1920
# define HEI		1080

/*
** Enum for Error Handling
*/

typedef enum		e_errors
{
	er_mem = 0,
	er_usg,
	er_inp,
	er_max,
	er_info
}					t_errors;

/*
** Enum for Operations, op_a move to b, op_b move to a
*/

typedef enum		e_opers
{
	op_a = 0,
	op_b,
	op_ab
}					t_opers;

/*
** Linked List struct
*/

typedef struct		s_nbr
{
	long long		val;
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
	int				width;
	int				max_val;

	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;

	int				v_flag;
	int				t_flag;
	int				i_flag;
	int				cnt;
	int				ops;
	int				pause;
	int				color;
}					t_prop;

/*
** Input Processing and Errors
*/

void				check_array(char **array);
void				ft_puterr(int x);
void				check_str(char *input);
void				arg_to_str(char *input, t_prop *xt);
void				process_input(t_prop *xt);
void				check_duplicates(t_prop *xt);
void				check_stack(t_prop *xt);

/*
** Stack Manipulation
*/

t_nbr				*new_node(long long content);
void				push_top(t_nbr **stack, t_nbr **stack2);
void				rotate_stack(t_nbr **stack);
void				rotate_stack_2(t_nbr **stack, t_nbr **stack2);
void				swap_top(t_nbr **stack);
void				swap_top_2(t_nbr **stack, t_nbr **stack2);
void				rrotate_stack(t_nbr **stack);
void				rrotate_stack_2(t_nbr **stack, t_nbr **stack2);

/*
** Validation
*/

int					is_sorted(t_nbr *head);
void				apply_instruction(char *line, t_prop *xt);
void				check_stacks(t_prop *xt);

/*
** Visualiser
*/

void				draw_all(t_prop *xt);
int					draw_one(t_prop *xt);
void				redraw(t_prop *xt);
int					onupdate(t_prop *xt);
void				visualise(t_prop *xt);
int					key_hook_press(int keycode, t_prop *xt);
void				draw_stack(t_prop *xt, t_nbr *stack, int x);
void				draw_bases(t_prop *xt);
void				draw_background(t_prop *xt);

/*
** Tools
*/

int					get_max(t_nbr *stack);
int					get_len(t_nbr *stack);
int					give_len(t_prop *xt, int val);
void				get_width_max(t_prop *xt);
void				init_window(t_prop *xt);
void				init_prop(t_prop *xt);
void				get_minmax(int len, t_prop *xt, t_nbr *stack);

#endif
