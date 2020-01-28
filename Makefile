# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 11:55:32 by asolopov          #+#    #+#              #
#    Updated: 2020/01/28 14:06:34 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 -Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# PUSH_SWAP files

PUSH_SWAP_EXE		= push_swap

PUSH_SWAP_SRC		= main.c\
					err_manager.c\
					extra.c\
					input_processing.c\
					input_tools.c\
					ops_push_top.c\
					ops_rotate_stack.c\
					ops_rrotate_stack.c\
					ops_swap_top.c\
					sort_conditions.c\
					sort_quick_insert.c\
					sort_rotations.c\
					sort_routines.c\
					sort_three_vals.c\
					sort_tofit_rules.c\
					stack_data.c\
					stack_get_moves.c\
					stack_get_pivot.c\
					stack_push_data.c

PUSH_SWAP_FILES		= $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC))

# CHECKER files

CHECKER_EXE			= checker

CHECKER_SRC			= main.c\
					err_manager.c\
					input_process.c\
					input_tools.c\
					ops_push_top.c\
					ops_rotate_stack.c\
					ops_rrotate_stack.c\
					ops_swap_top.c\
					sort_apply_ops.c\
					sort_verify.c\
					visualiser_control.c\
					visualiser_draw.c\
					visualiser_tools.c\
					visualiser.c

CHECKER_FILES		= $(addprefix $(CHECKER_DIR), $(CHECKER_SRC))

# Directories

PUSH_SWAP_DIR		= ./srcs/push_swap/
CHECKER_DIR			= ./srcs/checker/
LIBFT_DIR			= ./libft/

# Libraries

LIBFT_NAME			= libft.a
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
MLX_LNK				= /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit
MLX_HOME			= /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

.PHONY: all clean fclean re

all: $(LIBFT_NAME) $(PUSH_SWAP_EXE) $(CHECKER_EXE)

$(PUSH_SWAP_EXE): 
	@echo "$(RED)Compiling push_swap...$(RES)"
	@gcc -o $(PUSH_SWAP_EXE) $(CFLAGS) $(LIBFT_A) $(PUSH_SWAP_FILES)
	@echo "$(GREENB)$(PUSH_SWAP_EXE) $(GREEN)done.$(RES)"

$(CHECKER_EXE):
	@echo "$(RED)Compiling checker...$(RES)"
	@gcc -o $(CHECKER_EXE) $(CFLAGS) $(LIBFT_A) $(CHECKER_FILES) -L $(MLX_LNK)
	@echo "$(GREENB)$(CHECKER_EXE) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

clean:
	@echo "$(RED)Removing Object Files...$(RES)"
	@Make clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

fclean: clean
	@echo "$(RED)Removing Executables & Library...$(RES)"
	@/bin/rm -f $(PUSH_SWAP_EXE)
	@/bin/rm -f $(CHECKER_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all