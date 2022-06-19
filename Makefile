# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 20:00:16 by czang             #+#    #+#              #
#    Updated: 2022/06/19 20:20:16 by czang            ###   ########lyon.fr    #
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

$(OPATH)/%.o:	%.c $(INC) config/srcs.mk Makefile make_mlx
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

memoire:		CFLAGS += $(MEMFLAGS)
memoire:		re

re:				fclean all

make_mlx:		
	@make -C mlx
clean_mlx:		
	@make clean -C mlx

clean:			clean_mlx
	@$(RM) $(OBJS)
	@$(RMF) $(OPATH)

fclean:			clean
	@$(RM) $(NAME)

.PHONY: re clean fclean all
