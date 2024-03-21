# Target name
NAME = fdf
# Compiler
CC = cc
# Compilation flags
FLAGS = -g -ggdb -pedantic -Wall -Wextra -Werror
# MiniLibX configuration
MLX = -Lminilibx-linux minilibx-linux/libmlx_Linux.a -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -Iinclude
# Library paths
LIBFT_PATH := ./libft
LIBMLX_PATH := ./minilibx-linux
# Library files
LIBFT := $(LIBFT_PATH)/libft.a
LIBMLX := $(LIBMLX_PATH)/libmlx_Linux.a
# MiniLibX repository URL
MLX_URL := https://github.com/42Paris/minilibx-linux.git
# Source files
SRC = src/debug_utils.c \
      src/deploy_map.c \
      src/ft_checkfile.c \
      src/ft_drawline.c \
      src/hook_related_1.c \
      src/hook_related_2.c \
	  src/init.c \
	  src/key_press_related.c \
	  src/main.c \
	  src/mlx_related.c \
	  src/print_menu.c \
	  src/projection_related.c \
	  src/put_signature.c \
	  src/sphere_related.c \
	  src/utils.c \
	  src/zoom_related.c
# Main target
$(NAME): $(LIBMLX) $(LIBFT) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(LIBFT) $(MLX) -o $(NAME)
	echo
	echo "${BOLD}Created  -> ${RED}$(NAME)${NO_COLOR}"
# Build the LibFT library
$(LIBFT):
	make -C $(LIBFT_PATH) all
# Build the MiniLibX library
$(LIBMLX):
	@if [ ! -d "$(LIBMLX_PATH)" ]; then \
		$(MAKE) $(LIBMLX_PATH); \
	fi
	@make -C $(LIBMLX_PATH) all > /dev/null 2>&1
	echo
	echo "${BOLD}Created  -> ${GREEN}libmlx_Linux.a${NO_COLOR}"
# Download MiniLibX if not present
$(LIBMLX_PATH):
	@echo "${GREEN}${BOLD}Downloading minilibx${NO_COLOR}"
	git clone $(MLX_URL) $(LIBMLX_PATH) > /dev/null 2>&1
# Alias for download target
download: $(LIBMLX_PATH)

maps:
	if [ ! -d maps ]; then \
		git clone https://github.com/CapSte42/utility.git > /dev/null 2>&1; \
		mv utility/fdf/maps .; \
		echo "${YELLOW}${BOLD}--> Maps downloaded in ./maps/ <---${NO_COLOR}"; \
		rm -rf utility; \
	fi
# Build all target
all: $(NAME)
# Clean and rebuild target
re: fclean all
# Clean object files
clean:
	if [ -n "$$(find $(LIBFT_PATH) -name '*.o' -print -quit)" ]; then \
		make -C $(LIBFT_PATH) clean; \
		echo; \
		echo "${BOLD}${YELLOW}Cleaned object files${NO_COLOR}"; \
	fi
# Full clean
fclean: clean
	if [ -e $(LIBFT) ]; then \
		make -C $(LIBFT_PATH) fclean; \
		echo; \
		echo "${BOLD}${YELLOW}Removed  -> ${BLUE}libft.a${NO_COLOR}"; \
	fi
	if [ -e $(LIBMLX) ]; then \
		make -C $(LIBMLX_PATH) clean > /dev/null; \
		echo; \
		echo "${BOLD}${YELLOW}Removed  -> ${GREEN}libmlx_Linux.a${NO_COLOR}"; \
	fi
	if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo; \
		echo "${BOLD}${YELLOW}Removed  -> ${RED}$(NAME)${NO_COLOR}"; \
	fi
# Declare phony target
.PHONY: all clean fclean re download
# Silence all commands
.SILENT:
# ANSI color codes
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NO_COLOR = \033[0m
BOLD = \033[1m