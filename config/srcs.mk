PMAIN		:=	main/
PPARSING	:=	$(PMAIN)parsing/
PGRAPHICAL	:=	$(PMAIN)graphical/
PUTILS		:=	utils/
PGNL		:=	$(PUTILS)gnl/

SRCS		:=	$(PMAIN)so_long.c									\
				$(PPARSING)parsing.c								\
				$(PPARSING)parsing2.c								\
				$(PPARSING)print_error.c							\
				$(PGRAPHICAL)new_window.c							\
				$(PGRAPHICAL)init_sprite.c							\
				$(PGRAPHICAL)put_sprite.c							\
				$(PGRAPHICAL)init_screen_and_map.c					\
				$(PGRAPHICAL)init_and_put_player_exit_and_coin.c	\
				$(PGRAPHICAL)game.c									\
				$(PGRAPHICAL)player_move.c							\
				$(PUTILS)small_utils.c								\
				$(PGNL)get_next_line.c								\
				$(PGNL)get_next_line_utils.c
