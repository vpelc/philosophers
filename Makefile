# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 17:59:30 by vpelc             #+#    #+#              #
#    Updated: 2024/09/10 18:00:42 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Standard
NAME                = 

# Directories
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/

# Compiler and CFlags
CC                  = cc
CFLAGS              = -Wall -Werror -Wextra -g
RM                  = rm -f

# Additional flags
INCLUDES            = -I /usr/local/include

# Source files
SRCS                = main.c

# File paths
SRC                 = $(addprefix $(SRC_DIR), $(SRCS))
OBJ                 = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all:                $(NAME)

obj:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\033[1;31mDirectory already created.\033[0m"; \
	else \
		mkdir -p $(OBJ_DIR); \
		echo "\033[1;36mDirectory obj/ with files .o is being created...\033[0m"; \
	fi

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) -I$(INC) $(INCLUDES) -c $< -o $@
#	@echo "\033[1;32mFile $@ created.\033[0m";

$(NAME): $(OBJ) 
	@echo "\033[1;36mCompiling...\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBRARIES)
	@echo "\033[1;32mDone.\033[0m"

clean:
	@echo "\033[1;35mRemoving obj/...\033[0m"
	@$(RM) -r $(OBJ_DIR) 
	@echo "\033[1;32mAll Done for clean.\033[0m"

fclean: clean
	@echo "\033[1;35mRemoving...\033[0m"
	@$(RM) $(NAME)
	@echo "\033[1;32mDone.\033[0m"

re: fclean obj all

bonus: all

.PHONY: all obj clean fclean re