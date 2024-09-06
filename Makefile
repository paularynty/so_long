# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 12:05:04 by prynty            #+#    #+#              #
#    Updated: 2024/09/06 17:43:50 by prynty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color codes
RESET 		= \033[0;39m
BLACK		= \033[1;30m
DARK_RED	= \033[1;31m
DARK_GREEN	= \033[1;32m
DARK_YELLOW	= \033[1;33m
DARK_BLUE	= \033[1;34m
DARK_MAGENTA = \033[1;35m
DARK_CYAN	= \033[1;36m
DARK_GRAY	= \033[0;90m
LIGHT_GRAY	= \033[1;37m
RED			= \033[1;91m
ORANGE 		= \e[1m\e[38;5;202m
YELLOW 		= \033[0;93m
YELLOW_BOLD = \033[1;93m
GREEN		= \033[1;92m
BLUE 		= \033[0;94m
BLUE_BOLD 	= \033[1;94m
CYAN 		= \033[0;96m
CYAN_BOLD 	= \033[1;96m
MAGENTA 	= \033[1;95m
PINK		= \e[1m\e[38;5;212m
WHITE 		= \033[1;97m

# Terminal messages
OBJ_READY		= echo "📥 $(ORANGE)Compiled so_long files!$(RESET)"
BONUS_OBJ_READY	= echo "📥 $(ORANGE)Compiled so_long_bonus files!$(RESET)"
COMP_LIBFT		= echo "📝 $(YELLOW)Compiling Libft...$(RESET)"
LIBFT_READY		= echo "📝 $(YELLOW_BOLD)Libft compiled!$(RESET)"
SL_READY		= echo "🧮 $(GREEN)so_long ready!$(RESET)"
SL_BONUS_READY	= echo "🧮 $(GREEN)so_long_bonus ready!$(RESET)"
CLEANING		= echo "💧 $(CYAN)Cleaning...$(RESET)"
CLEANED			= echo "💧 $(CYAN_BOLD)Successfully cleaned all object files!$(RESET)"
FCLEANING		= echo "🧼 $(BLUE)Deep cleaning...$(RESET)"
FCLEANED		= echo "🧼 $(BLUE_BOLD)Successfully cleaned all executable files!$(RESET)"
REMAKE			= echo "✅ $(GREEN)Successfully cleaned and rebuilt everything!$(RESET)"

# Program names, directories, flags
NAME		= so_long
NAME_BONUS	= so_long_bonus
CFLAGS		= -Wall -Wextra -Werror
OSFLAGS		= -ldl -lglfw -pthread -lm
LIBFT		= ./$(LIBFT_DIR)/libft.a
LIBMLX		= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR	= ./libft
MLX_DIR		= ./MLX42
MLX_HEADER = -I $(MLX_DIR)/include
HEADERS = -I. $(MLX_HEADER) -I$(LIBFT_DIR)

# Source and object files
FILES 		= main.c \
			error_handling.c \
			game_images.c \
			game_init.c \
			game_movement.c \
			game_text.c \
			map_content.c \
			map_init.c \
			map_path.c \
			map_validation.c \

FILES_BONUS = main_bonus.c \
			error_handling_bonus.c \
			game_images_bonus.c \
			game_init_bonus.c \
			game_movement_bonus.c \
			game_text_bonus.c \
			map_content_bonus.c \
			map_init_bonus.c \
			map_path_bonus.c \
			map_validation_bonus.c \
			

SRCS		= $(addprefix srcs/, $(FILES))
SRCS_BONUS	= $(addprefix srcs/bonus/, $(FILES_BONUS))
OBJS		= $(addprefix objs/, $(FILES:.c=.o))
BONUS_OBJS	= $(addprefix objs/bonus/, $(FILES_BONUS:.c=.o))

.DEFAULT_GOAL = all

# Ensure libft is always checked and built if needed
$(LIBFT):
	@if [ ! -f $(LIBFT) ]; then \
		$(COMP_LIBFT); \
		make -s -C $(LIBFT_DIR) > /dev/null; \
		$(LIBFT_READY); \
	fi

# Ensure that MLX42 is cloned, built, and linked
$(LIBMLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null; \
	fi
	@make -s -C $(MLX_DIR)/build -j4 > /dev/null

# Ensure necessary directories for object files
objs:
	@mkdir -p objs/
	@mkdir -p libft/objs/

objs/bonus:
	@mkdir -p objs/bonus/
	@mkdir -p libft/objs/

# Compile object files
objs/%.o: srcs/%.c | objs
	@cc $(FLAGS) -c $< -o $@ $(HEADERS)

objs/bonus/%.o: srcs/bonus/%.c | objs/bonus
	@cc $(FLAGS) -c $< -o $@ $(HEADERS)

# Main program target
$(NAME): $(OBJS)
	@cp $(LIBFT) .
	@$(OBJ_READY)
	@cc -g $(OBJS) $(LIBMLX) $(LIBFT) $(OSFLAGS) -o $(NAME)
	@chmod 777 $(NAME)
	@$(SL_READY)

# Bonus program target
$(NAME_BONUS): $(BONUS_OBJS)
	@cp $(LIBFT) .
	@$(BONUS_OBJ_READY)
	@cc -g $(BONUS_OBJS) $(LIBMLX) $(LIBFT) $(OSFLAGS) -o $(NAME_BONUS)
	@chmod 777 $(NAME_BONUS)
	@$(SL_BONUS_READY)

# Standard targets
all: $(LIBMLX) $(LIBFT) $(NAME)

bonus: $(LIBMLX) $(LIBFT) $(NAME_BONUS)

# Cleaning targets
clean:
	@$(CLEANING)
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf objs/
	@rm -rf $(MLX_DIR)/build
	@make clean -s -C libft
	@$(CLEANED)

fclean: clean
	@$(FCLEANING)
	@rm -rf $(NAME) $(NAME_BONUS)
	@make fclean -s -C libft
	@rm -rf libft.a
	@rm -rf $(MLX_DIR)
	@$(FCLEANED)

re:	fclean all
	@$(REMAKE)

.PHONY: all clean fclean re libmlx libft bonus