# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solopov <solopov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 11:55:32 by asolopov          #+#    #+#              #
#    Updated: 2019/12/20 10:41:32 by solopov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3
GREEN		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[1;31m

# Executable files

NAME	=	push_swap

EXECSRC		=	main.c\
				get_input.c\
				process_input.c\
				swap_top.c\
				push_top.c\
				rotate_stack.c\
				rrotate_stack.c\
				sort_stack_small.c\
				err_manager.c

EXECBOBJ	= $(EXECSRC:.c=.o)

EXECSRCS	= $(addprefix $(SRCDIR), $(EXECSRC))
EXECOBJS	= $(addprefix $(SRCDIR), $(EXECBOBJ))

# Libft files

LIBNAME		= libft.a

LIBSRC		= ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_safestrjoin.c\
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_realloc.c \
			get_next_line.c \

LIBOBJ		= $(LIBSRC:.c=.o)

LIBSRCS		= $(addprefix $(LIBDIR), $(LIBSRC))
LIBOBJS		= $(addprefix $(LIBDIR), $(LIBOBJ))
LIBFILE		= $(addprefix $(LIBDIR), $(LIBNAME))

# Directories

LIBDIR		= ./libft/
SRCDIR		= ./srcs/
OBJDIR		= ./obj/
INCDIR		= ./includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBNAME)
	@echo "$(RED)Compiling push_swap$(EXECNAME)...$(RES)"
	gcc -o $(NAME) $(CFLAGS) $(LIBFILE) $(EXECSRCS)
	@echo "$(EXECNAME)push_swap Compiled!"

$(LIBNAME):
	@echo "$(RED)Creating library...$(RES)"
	@gcc -c $(CFLAGS) $(LIBSRCS)
	@ar rc $(LIBNAME) $(LIBOBJ)
	@ranlib $(LIBNAME)
	@mv $(LIBOBJ) $(LIBDIR)
	@mv $(LIBNAME) $(LIBDIR)
	@echo "$(GREEN)Library Created.$(RES)"

clean:
	@echo "$(RED)Deleting Objects...$(RES)"
	@/bin/rm -f $(LIBOBJS)
	@/bin/rm -f $(EXECOBJS)
	@echo "$(GREEN)Objects deleted.$(RES)"

fclean: clean
	@echo "$(RED)Deleting Libraries...$(RES)"
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIBFILE)
	@/bin/rm -f $(LIBNAME)
	@echo "$(GREEN)Libraries deleted.$(RES)"

re: fclean all