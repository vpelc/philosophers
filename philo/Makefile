# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 17:59:30 by vpelc             #+#    #+#              #
#    Updated: 2024/11/29 13:43:50 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= philo

# Directories
LIBFT				= ./libft/libft.a
INC					= ./include/
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/

# Compiler and CFlags
CC                  = cc
CFLAGS              = -Wall -Werror -Wextra -fsanitize=thread
RM                  = rm -rf

# Source files
SRCS				= main.c init_philo.c utils.c debug.c \
					check_args.c routine.c monitor.c exit.c

# File paths
SRC					= $(addprefix $(SRC_DIR), $(SRCS))
OBJ					= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all:	$(NAME)

$(LIBFT):
	@echo "\033[1;36mCompiling libft...\033[0m"
	@make -C ./libft
	@echo "\033[1;32mLibft.a has been created.\n\033[0m"

obj:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\033[1;31mDirectory already created.\033[0m"; \
	else \
		mkdir -p $(OBJ_DIR); \
		echo "\033[1;30mDirectory obj/ with files .o is being created...\033[0m"; \
	fi

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
#	@echo "\033[1;32mFile $@ created.\033[0m";

$(NAME): $(LIBFT) obj $(OBJ) 
	@echo "\033[1;36mCompiling...\033[0m"
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo "\033[1;32mDone.\n\033[0m"

clean:
	@echo "\033[1;35mRemoving obj/...\033[0m"
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;35mRemoving libft...\033[0m"
	@make clean -C ./libft
	@echo "\033[1;32mAll Done for clean.\n\033[0m"

fclean: clean
	@echo "\033[1;35mRemoving exec...\033[0m"
	@$(RM) $(NAME)
	@echo "\033[1;35mRemoving exec libft...\033[0m"
	@make fclean -C ./libft
	@echo "\033[1;32mDone.\n\033[0m"

re: fclean obj all

#debug: $(CFLAGS) += -g3 -D DEBUG=1
#debug: re

.PHONY: all obj clean fclean re debug