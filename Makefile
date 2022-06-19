# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 14:12:11 by czang             #+#    #+#              #
#    Updated: 2022/06/18 15:38:05 by czang            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

include 	config/srcs.mk

NAME		:=	so_long
IPATH		:=	Includes
OPATH		:=	.OBJ
PMLX		:=	mlx/
MEMFLAGS	:=	-fsanitize=address -g3
CFLAGS		:=	-Wall -Werror -Wextra
IFLAGS		:=	-I $(IPATH)
MLXFLAGS	:=	-I $(PMLX) -L $(PMLX) -lmlx -framework OpenGL -framework Appkit
OBJS		:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
INC			:=	$(addprefix $(IPATH)/, so_long.h)
RMF			:=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
	@$(CC) $(MLXFLAGS) $(CFLAGS) $^ -o $@

re:				fclean all

$(OPATH)/%.o:	%.c $(INC) config/srcs.mk Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

memoire:		CFLAGS += $(MEMFLAGS)
memoire:		re

clean:
	@$(RM) $(OBJS)
	@$(RMF) $(OPATH)

fclean:			clean
	@$(RM) $(NAME)

PHONY: re clean fclean all
