# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 11:55:32 by asolopov          #+#    #+#              #
#    Updated: 2019/12/25 15:42:40 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3
GREEN		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[1;31m

# PUSH_SWAP files

PUSH_SWAP_EXE		=	push_swap

PUSH_SWAP_SRC		= main.c\
					extra.c\
					get_input.c\
					process_input.c\
					swap_top.c\
					push_top.c\
					rotate_stack.c\
					rrotate_stack.c\
					sort_med.c\
					sort_small.c\
					sorting_disp.c\
					err_manager.c

PUSH_SWAP_OBJ		= $(PUSH_SWAP_SRC:.c=.o)

PUSH_SWAP_FILES		= $(addprefix $(PUSH_SWAP_DIR), $(PUSH_SWAP_SRC))

# CHECKER files

CHECKER_EXE			=	checker

CHECKER_SRC			= main.c\
					extra.c\
					get_input.c\
					process_input.c\
					swap_top.c\
					push_top.c\
					rotate_stack.c\
					rrotate_stack.c\
					sort_med.c\
					sort_small.c\
					sorting_disp.c\
					err_manager.c

CHECKER_OBJ			= $(PUSH_SWAP_SRC:.c=.o)

CHECKER_FILES		= $(addprefix $(CHECKER_DIR), $(CHECKER_SRC))

# Directories

PUSH_SWAP_DIR		= ./srcs/push_swap/
CHECKER_DIR			= ./srcs/checker/
LIBFT_DIR			= ./libft/
INCLUDES_DIR		= ./includes/

# Libraries

LIBFT_NAME			= libft.a
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

.PHONY: all clean fclean re

all: $(PUSH_SWAP_EXE)

$(PUSH_SWAP_EXE): $(LIBFT_NAME)
	@echo "$(RED)Compiling push_swap...$(RES)"
	@gcc -o $(PUSH_SWAP_EXE) $(CFLAGS) $(LIBFT_A) $(PUSH_SWAP_FILES)
	@echo "$(GREEN)push_swap Compiled!$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Creating library...$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Library Created.$(RES)"

$(CHECKER_EXE): $(LIBNAME)
	@echo "$(RED)Compiling checker...$(RES)"
	gcc -o $(CHECKER_EXE) $(CFLAGS) $(LIBFILE) $(EXECSRCS)
	@echo "$(EXECNAME)checker Compiled!"

clean:
	@echo "$(RED)Deleting Objects...$(RES)"
	@/bin/rm -f $(LIBOBJS)
	@/bin/rm -f $(EXECOBJS)
	@echo "$(GREEN)Objects deleted.$(RES)"

fclean: clean
	@echo "$(RED)Deleting Executables and Object Files...$(RES)"
	@/bin/rm -f $(PUSH_SWAP_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)Executables and Object Files deleted.$(RES)"

re: fclean all