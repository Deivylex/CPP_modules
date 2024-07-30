# Variables
NAME            = megaphone
CC              = c++
CFLAGS          = -Wall -Werror -Wextra -std=c++98

# Directories
SRC_DIR         = src/
OBJ_DIR         = obj/
INC_DIR         = include/

# Source and object files
SRC_FILES       = megaphone.cpp
OBJ_FILES       = $(SRC_FILES:.cpp=.o)

# Paths
SRC             = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ             = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# Control codes
RED             = \033[1;91m
YELLOW          = \033[1;33m
GREEN           = \033[1;32m
CYAN            = \033[1;36m
PURPLE          = \033[1;35m
END             = \033[0m
RESET           = $(END)  # Define RESET if used for resetting colors

# All rule
all: $(NAME)

# Compile the executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# Compile objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo "$(GREEN)Finished [$@]$(RESET)"

# Clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(BLUE)Deleting all objects from $(OBJ_DIR)...$(RESET)"; \
	else \
		echo "No objects to remove."; \
	fi;

# Fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME)...$(RESET)"; \
	else \
		echo "No executable to remove."; \
	fi;

# Re rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re
